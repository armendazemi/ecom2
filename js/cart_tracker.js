'use strict';
const formatter = window.ecomUtils.priceFormatter;

// Create a new function that wraps the formatter
const formatPrice = (number) => formatter(number) + 'kr';

document.addEventListener('DOMContentLoaded', () => {
  getAndStoreCartState();

  window.getCartState = getCartState;
  window.setCartState = setCartState;
  window.clearCartState = clearCartState;

  window.addEventListener('cart:updated', () => {
    updateCartPrice();
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
  const cards = document.querySelectorAll('.product-card-cart-preview[data-variant-id="' + variantId + '"]');
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
  if (window.location.href.includes('/w/checkout')) {

    if (data.order_items.length === 0) {
      window.location.href = '/w/cart';
      return;
    }

    const paymentResponse = await fetch('/w/checkout/payment', {
      mehtod: 'GET',
      headers: {
        Accept: 'application/json',
      },
    });

    if (!paymentResponse.ok) {
      console.error('Failed to update payment');
      return;
    }

    if (window._klarnaCheckout) {
      _klarnaCheckout((api) => {
        api.resume();
      });
    }
  }

  cards.forEach((card) => {
    card.remove();
  });
  setCartState(data);
  checkForPotentialCartRedirect(data);
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

function updateCartPrice () {
  const cartState = getCartState();
  const sideCartTotalPriceElement = document.getElementById('side-cart__total-price');

  if (!cartState || !sideCartTotalPriceElement) {
    return;
  }

  const sideCartHasItemsElement = document.querySelector('.side-cart__subtotal--has-items');
  const sideCartNoItemsElement = document.querySelector('.side-cart__subtotal--empty');
  if (cartState.order_items.length === 0) {
    sideCartHasItemsElement.classList.add('d-none');
    sideCartNoItemsElement.classList.remove('d-none');
  } else {
    sideCartHasItemsElement.classList.remove('d-none');
    sideCartNoItemsElement.classList.add('d-none');

  }

  const totalDiscountValue = Number(cartState.order.discount_total);
  const cartTotal = window.showTaxes ? cartState.order.item_total : cartState.order.item_pre_tax_total;
  const formattedPrice = formatPrice(cartTotal - totalDiscountValue);
  sideCartTotalPriceElement.textContent = `${formattedPrice}`;

  if (window.location.href.includes('checkout')) {
    updateCheckoutPrice(cartState);
    updateCheckoutItems(cartState);
  }
}

function updateCheckoutPrice (cartState) {
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

  productCountElement.textContent = productCount > 1 || productCount === 0 ? `${productCount} produkter` : `${productCount} produkt`;
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
}

function updateCheckoutItems (cartState) {
  const checkoutItemsElement = document.querySelectorAll('.checkout-wrapper__items .product-card-cart-preview');

  if (!checkoutItemsElement) {
    return;
  }
  cartState.order_items.forEach((item) => {
    const variantId = item.variant_id;

    const checkoutItem = Array.from(checkoutItemsElement).find((element) => {
      return Number(element.getAttribute('data-variant-id')) === variantId;
    });

    if (!checkoutItem) {
      return;
    }

    const checkoutItemPrice = checkoutItem.querySelector('.product-card-cart-preview__price');
    // Check if the item has a discount by comparing the amount to the original amount

    if (Number(item.original_amount) > Number(item.amount)) {
      const discountPrice = checkoutItemPrice.querySelector('.product-card-cart-preview__price-discount');
      const originalPrice = checkoutItemPrice.querySelector('.product-card-cart-preview__price-original');
      originalPrice.textContent = window.showTaxes ? formatPrice(item.original_amount) : formatPrice(item.original_amount_pre_tax);
      discountPrice.textContent = window.showTaxes ? formatPrice(item.amount) : formatPrice(item.pre_tax_amount);
    } else {
      const originalPrice = checkoutItemPrice.querySelector('.product-card-cart-preview__price-original');
      originalPrice.textContent = window.showTaxes ? formatPrice(item.original_amount) : formatPrice(item.original_amount_pre_tax);
    }
  });
}
