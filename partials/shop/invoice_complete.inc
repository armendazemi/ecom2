<div class="container">
  <div class="row justify-content-center">
    <div class="col-lg-8">

      <div class="d-flex flex-column align-items-center text-center row-gap-200 padding-bottom-600">
        <svg xmlns="http://www.w3.org/2000/svg" width="56" height="56" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="1.5" stroke-linecap="round" stroke-linejoin="round">
          <circle cx="12" cy="12" r="10"/>
          <path d="M9 12l2 2 4-4"/>
        </svg>
        <h1 class="display-md">{{ "Tack för din beställning!" | t }}</h1>
        <p class="text-secondary">{{ "Din faktura är på väg. Vi återkommer med mer information via e-post." | t }}</p>
      </div>

      <div class="d-flex flex-column row-gap-50 padding-y-300 border-top-1--soft border-bottom-1--soft padding-bottom-300 margin-bottom-400">
        <div class="d-flex justify-content-between">
          <span class="text-secondary">{{ "Ordernummer" | t }}</span>
          <span class="fw-semi">{{ cart.number }}</span>
        </div>
        <div class="d-flex justify-content-between">
          <span class="text-secondary">{{ "Datum" | t }}</span>
          <span>{{ cart.completed_at | date: '%e %b %Y' }}</span>
        </div>
        <div class="d-flex justify-content-between">
          <span class="text-secondary">{{ "E-post" | t }}</span>
          <span>{{ cart.email }}</span>
        </div>
        <div class="d-flex justify-content-between">
          <span class="text-secondary">{{ "Betalmetod" | t }}</span>
          <span>{{ cart.payment_method.presentation }}</span>
        </div>
      </div>

      <h2 class="display-sm margin-bottom-300">{{ "Din beställning" | t }}</h2>

      <div class="d-flex flex-column row-gap-300 margin-bottom-400">
        {% for item in cart.order_items %}
          {% assign displayOnly = true %}
          {% include 'order_item' %}
        {% endfor %}
      </div>

      <div class="d-flex flex-column row-gap-50 padding-y-300 border-top-1--soft">
        {% if customer.show_taxes %}
          <div class="d-flex justify-content-between text-secondary">
            <span>{{ "Delsumma" | t }}</span>
            <span>{{ cart.item_total | currency: 0 }}</span>
          </div>
          {% if cart.discount_total > 0 %}
            <div class="d-flex justify-content-between text-secondary">
              <span>{{ "Rabatt" | t }}</span>
              <span class="text-campaign">-{{ cart.discount_total | currency: 0 }}</span>
            </div>
          {% endif %}
          <div class="d-flex justify-content-between text-secondary">
            <span>{{ "Frakt" | t }}</span>
            <span>{{ cart.shipment_total | currency: 0 }}</span>
          </div>
          <div class="d-flex justify-content-between fw-semi padding-top-200 border-top-1--soft">
            <span>{{ "Totalt" | t }}</span>
            <span>{{ cart.total | currency: 0 }}</span>
          </div>
          <div class="d-flex justify-content-between text-secondary">
            <span>{{ "Varav moms" | t }}</span>
            <span>{{ cart.included_tax_total | currency: 0 }}</span>
          </div>
        {% else %}
          <div class="d-flex justify-content-between text-secondary">
            <span>{{ "Delsumma exkl. moms" | t }}</span>
            <span>{{ cart.pre_tax_item_total | currency: 0 }}</span>
          </div>
          {% if cart.discount_total > 0 %}
            <div class="d-flex justify-content-between text-secondary">
              <span>{{ "Rabatt" | t }}</span>
              <span class="text-campaign">-{{ cart.discount_total | currency: 0 }}</span>
            </div>
          {% endif %}
          <div class="d-flex justify-content-between text-secondary">
            <span>{{ "Frakt" | t }}</span>
            <span>{{ cart.shipment_total | currency: 0 }}</span>
          </div>
          <div class="d-flex justify-content-between fw-semi padding-top-200 border-top-1--soft">
            <span>{{ "Totalt exkl. moms" | t }}</span>
            <span>{{ cart.pre_tax_total | currency: 0 }}</span>
          </div>
        {% endif %}
      </div>

      <div class="padding-top-600">
        <a href="/" class="brand-button-secondary">{{ "Fortsätt handla" | t }}</a>
      </div>

    </div>
  </div>
</div>
