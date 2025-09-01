<modal-component id="newsletter-modal" class="default-modal bg-white">
  <div class="default-modal__header ">
    <h2 class="display-xs ">{{ "Nyhetsbrev titel" | t }}</h2>
    <button type="button" data-modal-action="close" data-modal-element="#newsletter-modal"
            class="icon-button large added-to-cart-toast__close-btn"
            aria-label="{{ "Stäng modalen för nyhetsbrev" | t }}">
      <svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" viewBox="0 0 14 14" fill="none">
        <path
          d="M6.99952 8.05376L1.92652 13.127C1.78802 13.2653 1.61394 13.3362 1.40427 13.3395C1.19477 13.3427 1.01752 13.2718 0.872524 13.127C0.72769 12.982 0.655273 12.8063 0.655273 12.6C0.655273 12.3937 0.72769 12.218 0.872524 12.073L5.94577 7.00001L0.872524 1.92701C0.73419 1.78851 0.663357 1.61443 0.660023 1.40476C0.656857 1.19526 0.72769 1.01801 0.872524 0.873012C1.01752 0.728178 1.19319 0.655762 1.39952 0.655762C1.60586 0.655762 1.78152 0.728178 1.92652 0.873012L6.99952 5.94626L12.0725 0.873012C12.211 0.734678 12.3851 0.663845 12.5948 0.660512C12.8043 0.657345 12.9815 0.728178 13.1265 0.873012C13.2714 1.01801 13.3438 1.19368 13.3438 1.40001C13.3438 1.60635 13.2714 1.78201 13.1265 1.92701L8.05327 7.00001L13.1265 12.073C13.2649 12.2115 13.3357 12.3856 13.339 12.5953C13.3422 12.8048 13.2714 12.982 13.1265 13.127C12.9815 13.2718 12.8059 13.3443 12.5995 13.3443C12.3932 13.3443 12.2175 13.2718 12.0725 13.127L6.99952 8.05376Z"
          fill="#030712"/>
      </svg>
    </button>
  </div>
  <div class="default-modal__content">
    <p class="text-secondary">{{ "Nyhetsbrev brödtext" | t }}</p>
  </div>
  <div class="default-modal__footer">
    <button type="button" class="brand-button-primary" data-modal-action="close"
            data-modal-element="#newsletter-modal">{{ "Stäng" | t }}</button>
  </div>
</modal-component>