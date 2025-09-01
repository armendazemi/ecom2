<div id="added-to-cart-toast" class="added-to-cart-toast"
     role="status"
     aria-live="polite"
     aria-atomic="true">

  <div class="added-to-cart-toast__header padding-bottom-150 d-flex justify-content-between align-items-center">
    <h2 class="added-to-cart-toast__heading display-xs"></h2>
    <button type="button" class="icon-button large added-to-cart-toast__close-btn">
      <svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" viewBox="0 0 14 14" fill="none">
        <path
          d="M6.99952 8.05376L1.92652 13.127C1.78802 13.2653 1.61394 13.3362 1.40427 13.3395C1.19477 13.3427 1.01752 13.2718 0.872524 13.127C0.72769 12.982 0.655273 12.8063 0.655273 12.6C0.655273 12.3937 0.72769 12.218 0.872524 12.073L5.94577 7.00001L0.872524 1.92701C0.73419 1.78851 0.663357 1.61443 0.660023 1.40476C0.656857 1.19526 0.72769 1.01801 0.872524 0.873012C1.01752 0.728178 1.19319 0.655762 1.39952 0.655762C1.60586 0.655762 1.78152 0.728178 1.92652 0.873012L6.99952 5.94626L12.0725 0.873012C12.211 0.734678 12.3851 0.663845 12.5948 0.660512C12.8043 0.657345 12.9815 0.728178 13.1265 0.873012C13.2714 1.01801 13.3438 1.19368 13.3438 1.40001C13.3438 1.60635 13.2714 1.78201 13.1265 1.92701L8.05327 7.00001L13.1265 12.073C13.2649 12.2115 13.3357 12.3856 13.339 12.5953C13.3422 12.8048 13.2714 12.982 13.1265 13.127C12.9815 13.2718 12.8059 13.3443 12.5995 13.3443C12.3932 13.3443 12.2175 13.2718 12.0725 13.127L6.99952 8.05376Z"
          fill="#030712"/>
      </svg>
    </button>
  </div>

  <div class="added-to-cart-toast__body d-flex column-gap-200 align-items-start padding-bottom-150">
    <div class="added-to-cart-toast__image">
      <img class="aspect-1 object-fit-cover" src="https://placehold.co/90x90" alt="" loading="lazy" width="90"
           height="90">
    </div>
    <div class="added-to-cart-toast__product-details d-flex flex-column row-gap-50">
      <p class="added-to-cart-toast__product-title fw-medium">1965 Automatic</p>
      <div class="added-to-cart-toast__product-variant text-sm text-secondary d-none"></div>
      <div class="added-to-cart-toast__product-price d-flex column-gap-150"></div>
    </div>
  </div>

  <div class="added-to-cart-toast__footer padding-top-150">
    <a href="{{ cart.url }}" class="brand-button-primary">{{ "Se varukorg" | t }}</a>
  </div>
</div>


<script>

  window.addEventListener('modalchange', (e) => {
    const target = e.detail.element;
    const action = e.detail.action;

    if (target !== '#side-cart') {
      return;
    }

    const lastAdded = window.getCartState().order_items.at(-1);
    const toast = document.getElementById('added-to-cart-toast');

    adjustToastPosition(toast);
    handleToastDisplayWith(lastAdded, toast);
    handleToastDisplay(action, toast);

  });

  document.addEventListener('click', (e) => {
    const target = e.target;
    if (target.classList.contains('added-to-cart-toast__close-btn')) {
      const toast = document.getElementById('added-to-cart-toast');
      handleToastDisplay('close', toast);
    }

    setupToastEvents();
  });

  function handleToastDisplay (action, element) {
    if (action === 'close') {
      window.ecomUtils.toggleVisibility(element, 'close');
    } else {
      window.ecomUtils.toggleVisibility(element, 'open');
      startCloseTimer(element, 3000, (element) => {
        window.ecomUtils.toggleVisibility(element, 'close');
      });
    }
  }

  // Starts a timer and calls the callback function on the element after the timer ends.
  function startCloseTimer (element, timer, callback) {
    // Clear any existing timer before starting a new one
    if (element.closeTimer) {
      clearTimeout(element.closeTimer);
    }

    // Start a new timer
    element.closeTimer = setTimeout(() => {
      if (callback && typeof callback === 'function') {
        callback(element);
      }
    }, timer);
  }

  function setupToastEvents () {
    const toast = document.getElementById('added-to-cart-toast');

    // Handle hover/focus events to pause the timer
    toast.addEventListener('mouseenter', () => {
      clearTimeout(toast.closeTimer);
    });

    toast.addEventListener('mouseleave', () => {
      // Restart the timer when the mouse leaves
      startCloseTimer(toast, 3000, (element) => {
        window.ecomUtils.toggleVisibility(element, 'close');
      });
    });

    toast.addEventListener('focusin', () => {
      clearTimeout(toast.closeTimer);
    });

    toast.addEventListener('focusout', () => {
      // Restart the timer when focus leaves
      startCloseTimer(toast, 3000, (element) => {
        window.ecomUtils.toggleVisibility(element, 'close');
      });
    });
  }

  function handleToastDisplayWith (orderItem, toast) {
    if (!orderItem) {
      return;
    }
    const quantity = orderItem.quantity;

    const heading = toast.querySelector('.added-to-cart-toast__heading');
    heading.textContent = quantity === 1
      ? `${window.getTranslation('Produkt tillagd i varukorgen')}`
      : `${quantity} ${window.getTranslation('produkter tillagda i varukorgen')}`;

    const image = toast.querySelector('.added-to-cart-toast__image img');
    image.src = orderItem.image.url_small ? orderItem.image.url_small : 'https://placehold.co/90x90';
    image.alt = orderItem.name;

    const title = toast.querySelector('.added-to-cart-toast__product-title');
    title.textContent = orderItem.name;

    const price = toast.querySelector('.added-to-cart-toast__product-price');
    console.log(orderItem.original_price, orderItem.price);
    if (Number(orderItem.original_price) > Number(orderItem.price)) {
      price.innerHTML = `
        <p class="text-secondary text-decoration-line-through">${window.ecomUtils.priceFormatter(window.showTaxes ? orderItem.original_amount : orderItem.original_amount_pre_tax)}</p>
        <p class="fw-bold text-campaign">${window.ecomUtils.priceFormatter(window.showTaxes ? orderItem.amount : orderItem.amount_pre_tax)}</p>
        `;
    } else {
      price.innerHTML = `<p class="text-secondary">${window.ecomUtils.priceFormatter(window.showTaxes ? orderItem.price : orderItem.price_pre_tax)}</p>`;
    }

    const options = orderItem.options;
    if (options.length > 0) {
      const variant = toast.querySelector('.added-to-cart-toast__product-variant');
      variant.classList.remove('d-none');
      variant.innerHTML = '';
      options.forEach(option => {
        const optionText = document.createElement('span');
        optionText.textContent = option.option_value.presentation[window.locale ? window.locale : 'default'];
        variant.appendChild(optionText);
      });
    }

  }

  // Adjust toast position to align with container class.
  function adjustToastPosition (toast) {
    const container = document.querySelector('.container');
    if (container && window.innerWidth >= 768) {
      const containerRect = container.getBoundingClientRect();
      const containerRight = containerRect.right;

      // Update the toast's right position
      toast.style.right = `${window.innerWidth - containerRight}px`;
    }
  }


</script>
