<div class="cart-summary padding-300 padding-lg-400 bg-brand-accent">
  <h2 class="display-sm margin-bottom-300">{{ "Orderöversikt" | t }}</h2>

  <div class="order-summary__body d-flex flex-column row-gap-200">
    <accordion-component class="d-block border-bottom-1--soft border-top-1--soft">
      <button type="button"
              class="clear-button fw-regular padding-y-300 justify-content-between w-100 h-auto padding-x-0">
        {{ "Lägg till kampanjkod" | t }}
        <svg class="rotate" xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 20 20"
             fill="none">
          <path
            d="M9.99576 12.5017C9.90645 12.5017 9.8234 12.4857 9.74659 12.4536C9.66978 12.4215 9.5993 12.3735 9.53513 12.3094L5.67201 8.44609C5.55201 8.32609 5.49409 8.19609 5.49826 8.05609C5.50256 7.91623 5.56506 7.78588 5.68576 7.66505C5.80659 7.54436 5.93562 7.48401 6.07284 7.48401C6.21006 7.48401 6.33909 7.54436 6.45992 7.66505L9.99992 11.2261L13.5608 7.66505C13.6762 7.54977 13.8039 7.49422 13.9439 7.49838C14.0837 7.50269 14.2141 7.56519 14.3349 7.68588C14.4556 7.80672 14.516 7.93575 14.516 8.07297C14.516 8.21019 14.4533 8.34116 14.3278 8.46588L10.4647 12.3094C10.395 12.3735 10.3217 12.4215 10.2449 12.4536C10.1681 12.4857 10.0851 12.5017 9.99576 12.5017Z"
            fill="#030712"/>
        </svg>
      </button>
      <div class="dropdown">
        <campaign-code data-error-modal="#campaignCodeErrorModal">
          <div class="d-flex align-items-center column-gap-150 padding-x-25 padding-top-25 padding-bottom-300">
            <input
              aria-label="{{ "Använd kampanjkod" | t }}"
              type="text"
              class="input-default flex-grow-1"
              placeholder="Kampanjkod"
              value="{{ cart.campaign_code }}">
            <button class="brand-button-primary button-large text-white">{{ "Använd" | t }}</button>
          </div>
        </campaign-code>
      </div>
    </accordion-component>

    <div class="order-summary__details d-flex flex-column row-gap-50 padding-bottom-200 border-bottom-1--soft">
      <div class="text-secondary d-flex justify-content-between text-secondary">
        <span>{{ "Delsumma" | t }}</span>
        <span class="text-right">{{ cart.item_total | currency: 0 }}</span>
      </div>

      {% if cart.discount_total > 0 %}
        <div class="text-secondary d-flex justify-content-between text-secondary">
          <span>{{ "Rabatt" | t }}</span>
          <span class="text-right text-campaign">-{{ cart.discount_total | currency: 0 }}</span>
        </div>
      {% endif %}

      <div class="text-secondary d-flex justify-content-between text-secondary">
        <span>{{ "Frakt" | t }}</span>
        <span class="text-right">{{ cart.shipment_total | currency: 0 }}</span>
      </div>
    </div>

    <div class="order-summary__total">
      <div class="text-secondary d-flex justify-content-between text-secondary">
        <span class="fw-semi">{{ "Totalt" | t }}</span>
        <span class="text-right">{{ cart.total | currency: 0 }}</span>
      </div>

      <div class="text-secondary d-flex justify-content-between text-secondary">
        <span class="">{{ "Varav moms" | t }}</span>
        <span class="text-right ">{{ cart.included_tax_total | currency: 0 }}</span>
      </div>
    </div>
  </div>

  <div class="order-summary__cta margin-top-300">
    <a href="{{ cart.checkout_url }}" class="brand-button-primary">{{ "Checkout" | t }}</a>
  </div>
</div>