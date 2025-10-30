<accordion-component class="d-block border-bottom-1--soft {% if forloop.first %}border-top-1--soft{% endif %}">
  <button type="button"
          class="clear-button fw-regular padding-y-300 justify-content-between w-100 h-auto padding-x-0">

    <span>{{ order.completed_at | date: '%e %b %Y' }}</span>
    <span>{{ "Ordernr" | t }}: {{ order.number }}</span>
    <span>{{ "Status" | t }}: {{ order.shipment_state | t }}</span>
    <span>{{ order.order_items.size }} {% if order.order_items.size == 1 %}{{ "artikel" | t }}{% else %}{{ "artiklar" | t }}{% endif %}</span>
    <svg class="rotate" xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 20 20"
         fill="none">
      <path
        d="M9.99576 12.5017C9.90645 12.5017 9.8234 12.4857 9.74659 12.4536C9.66978 12.4215 9.5993 12.3735 9.53513 12.3094L5.67201 8.44609C5.55201 8.32609 5.49409 8.19609 5.49826 8.05609C5.50256 7.91623 5.56506 7.78588 5.68576 7.66505C5.80659 7.54436 5.93562 7.48401 6.07284 7.48401C6.21006 7.48401 6.33909 7.54436 6.45992 7.66505L9.99992 11.2261L13.5608 7.66505C13.6762 7.54977 13.8039 7.49422 13.9439 7.49838C14.0837 7.50269 14.2141 7.56519 14.3349 7.68588C14.4556 7.80672 14.516 7.93575 14.516 8.07297C14.516 8.21019 14.4533 8.34116 14.3278 8.46588L10.4647 12.3094C10.395 12.3735 10.3217 12.4215 10.2449 12.4536C10.1681 12.4857 10.0851 12.5017 9.99576 12.5017Z"
        fill="#030712"/>
    </svg>
  </button>
  <div class="dropdown">
    <div class="padding-y-300 border-top-1--soft">
      {% for item in order.order_items %}
        {% assign displayOnly = true %}
        {% include 'order_item' %}
      {% endfor %}

      <div class="order-details d-flex flex-column padding-y-300">
        <div class="d-flex justify-content-between">
          <span class="text-secondary">{{ "Totalt" | t }}</span>
          <span class="text-right fw-semi">{{ order.total | currency: 0 }}</span>
        </div>

        <div class="d-flex justify-content-between padding-bottom-300">
          <span class="text-secondary">{{ "Status" | t }}</span>
          <span class="text-right fw-semi">{{ order.shipment_state | t }}</span>
        </div>

        <span class="text-secondary">{{ "Order datum" | t }}: {{ order.completed_at | date: '%e %b %Y' }}</span>
        <span>{{ "Ordernr" | t }}: {{ order.number }}</span>
        <span>{{ "Betalmetod" | t }}: {{ order.payment_method.presentation }}</span>
        <span>{{ "Leveransaddress" | t }}: {{ order.ship_address.address1 }}, {{ order.ship_address.zipcode }}, {{ order.ship_address.city }}</span>

      </div>
    </div>
  </div>
</accordion-component>