'use strict';
const formatter = window.ecomUtils.priceFormatter;

// Create a new function that wraps the formatter
const formatPrice = (number) => formatter(number);

document.addEventListener('DOMContentLoaded', () => {
  getAndStoreCartState();

  window.getCartState = getCartState;
  window.setCartState = setCartState;
  window.clearCartState = clearCartState;

  window.addEventListener('cart:updated', () => {
    updateCheckoutPrice();
  });

  window.addEventListener('cart:update', (event) => {
    setCartState(event.detail);
  });

  window.addEventListener('click', (event) => {
    if (event.target.classList.contains('remove-variant')) {
      handleVariantRemove(event);
    }
  });
});

async function getAndStoreCartState () {
  const url = '/w/cart?associations[]=variant';
  const response = await fetch(url, {
    method: 'GET',
    headers: {
      Accept: 'application/json',
    },
  });

  if (!response.ok) {
    console.error('Failed to fetch cart state');
    return;
  }

  const data = await response.json();
  setCartState(data);
}

function setCartState (data) {
  if (typeof data === 'object') {
    sessionStorage.setItem('cartState', JSON.stringify(data));
    window.dispatchEvent(new CustomEvent('cart:updated', { detail: data }));
    window.dispatchEvent(new CustomEvent('cart:items-change', { detail: { count: data.order_items.reduce((total, item) => total + item.quantity, 0) } }));
  }
}

async function handleVariantRemove (event) {
  const variantId = event.target.getAttribute('data-variant-id');
  const cards = document.querySelectorAll('.order-item[data-variant-id="' + variantId + '"]');
  const url = '/w/cart/order_items?associations[]=variant';

  if (window._klarnaCheckout && window.location.href.includes('/w/checkout')) {
    window._klarnaCheckout((api) => {
      api.suspend();
    });
  }

  const response = await fetch(url, {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
    },
    body: JSON.stringify({
      order_items: [
        {
          variant_id: variantId,
          quantity: 0,
        },
      ],
    }),
  });

  if (!response.ok) {
    console.error('Failed to remove item from cart');
    return;
  }
  const data = await response.json();

  // Update Klarna widget and redirect to cart page (if empty) only if we are on the checkout page
  if (window.location.href.includes('/w/cart')) {

    if (data.order_items.length === 0) {
      window.location.href = '/w/cart';
      return;
    }

    cards.forEach((card) => {
      card.remove();
    });
    setCartState(data);
  }
}

function checkForPotentialCartRedirect (data) {
  if (data.order_items.length === 0 && window.location.href.includes('checkout')) {
    window.location.href = '/w/cart';
  }
}

function getCartState () {
  return JSON.parse(sessionStorage.getItem('cartState'));
}

function clearCartState () {
  sessionStorage.removeItem('cartState');
}

function updateCheckoutPrice () {
  if (!window.location.href.includes('/w/cart')) {
    return;
  }
  const cartState = getCartState();
  const productCountElement = document.getElementById('checkout-product-count');
  const combinedArticlePriceElement = document.getElementById('combined-article-price');
  const discountPriceElement = document.getElementById('discount-price');
  const shippingPriceElement = document.getElementById('shipping-price');
  const taxPriceElement = document.getElementById('tax-price');
  const totalPriceElement = document.getElementById('total-price');

  if (!combinedArticlePriceElement || !taxPriceElement || !totalPriceElement) {
    console.error('Failed to update checkout price, one or more elements are missing');
    return;
  }

  const productCount = cartState.order_items.reduce((acc, item) => acc + item.quantity, 0);
  const taxTotal = Number(cartState.order.included_tax_total);
  const shippingTotal = Number(cartState.order.shipment_total);
  const originalCombinedArticlePrice = cartState.order_items.reduce((acc, item) => acc + Number(window.showTaxes ? item.original_amount : item.original_amount_pre_tax), 0);
  const currentCombinedArticlePrice = cartState.order_items.reduce((acc, item) => acc + Number(window.showTaxes ? item.amount : item.pre_tax_amount), 0);

  // For order discounts
  const orderDiscount = Number(cartState.order.discount_total);

  // For item discounts
  let orderItemsDiscount = 0;
  if (originalCombinedArticlePrice !== currentCombinedArticlePrice) {
    orderItemsDiscount = originalCombinedArticlePrice - currentCombinedArticlePrice;
  }

  productCountElement.innerHTML = String(productCount);
  combinedArticlePriceElement.textContent = formatPrice(originalCombinedArticlePrice);
  taxPriceElement.textContent = formatPrice(taxTotal);
  discountPriceElement.textContent = formatPrice(orderDiscount + orderItemsDiscount);

  // Hide on 0 discount
  if (orderItemsDiscount === 0 && orderDiscount === 0) {
    discountPriceElement.closest('div').classList.add('d-none');
  }

  if (shippingPriceElement) {
    shippingPriceElement.textContent = formatPrice(shippingTotal);
  }

  const cartTotal = window.showTaxes ? cartState.order.total : cartState.order.pre_tax_total;
  totalPriceElement.textContent = formatPrice(cartTotal);

  window.dispatchEvent(new CustomEvent('checkout:price-updated'));
}
