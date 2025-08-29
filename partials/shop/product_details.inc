<product-wrapper>
  <div class="product-single d-flex flex-column row-gap-300">

    <div class="product-single__header d-flex flex-column row-gap-100">
      <div
        class="product-single__badges d-flex gap-50 justify-content-start align-items-start">
        {%-comment-%} If newer than 30 days, show new badge {%-endcomment-%}
        {% assign today_ts = "now" | date: "%s" | plus: 0 %}
        {% assign available_ts = product.available_on | date: "%s" | plus: 0 %}

        {%- comment -%} seconds difference {%- endcomment -%}
        {% assign diff = today_ts | minus: available_ts %}

        {%- comment -%} 30 days in seconds = 60*60*24*30 = 2592000 {%- endcomment -%}
        {% if diff < 2592000 and diff >= 0 %}
          <span class="default-badge bg-brand-bold">{{ "New" | t }}</span>
        {% endif %}

        {% if product.prices.default.amount > product.prices.current.amount %}
          <span class="default-badge bg-error-bold">{{ "Sale" | t }}</span>
        {% endif %}
      </div>

      <div class="product-single__heading">
        <h1 class="display-lg">{{ product.name }}</h1>
        <p class="product-single__sku text-secondary d-none">{{ product.sku }}</p>
        {% if product.properties.size > 0 %}
          <div class="product-single__properties">
            {% for prop in product.properties %}
              {% if prop.option_category.name contains "Display" %}
                <span class="text-sm text-secondary">{{ prop.value }}</span>
              {% endif %}
            {% endfor %}
          </div>
        {% endif %}
      </div>

      <div class="product-single__price d-flex column-gap-150">
        {% if product.prices.default.amount > product.prices.current.amount %}
          <p
            class="product-single__price display-sm text-tertiary text-decoration-line-through mb-0">{{ product.prices.default.amount | currency: 0 }}</p>
          <p
            class="product-single__price display-sm fw-bold text-campaign ">
            {{ product.prices.current.amount | currency: 0 }}
          </p>
        {% else %}
          <p
            class="product-single__price display-sm fw-bold text-primary mb-0">{{ product.price | currency: 0 }}</p>
        {% endif %}
      </div>

      <div class="product-single__description">
        <p class="text-secondary">{{ product.description }}</p>
      </div>
    </div>

    <div class="product-single__cta d-flex column-gap-150 align-items-start">
      {% if lists.global-settings.rows[0].quantity_selector == "true" %}
        {% include 'quantity_selector' %}
      {% endif %}
      <button type="submit" class="brand-button-primary w-100">{{ "Lägg till" | t }}</button>
    </div>

    {% if lists.product-usp.rows.size > 0 %}
      <ul class="product-single__usp d-flex flex-column row-gap-150 list-unstyled m-0 p-0">
        {% for usp in lists.product-usp.rows %}
          <li class="d-flex column-gap-150 align-items-center justify-content-start">
            <div class="product-single__icon-wrapper">
              <img src="{{ usp.icon }}" loading="lazy" width="20" height="20" alt="">
            </div>
            <p class="text-secondary mb-0">{{ usp.text }}</p>
          </li>
        {% endfor %}
      </ul>
    {% endif %}

    <accordion-group class="border-bottom-1--soft">
      {% if product.short_description.size > 0 %}
        <accordion-component class="border-top-1--soft d-block">
          <h2 class="padding-y-200">
            <button type="button" class="clear-button padding-x-0 w-100 justify-content-between fw-regular">
              {{ "Produktdetaljer" | t }}
              <svg class="rotate" xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24"
                   fill="none">
                <path
                  d="M11.9998 14.677C11.8793 14.677 11.7671 14.6577 11.6633 14.6192C11.5594 14.5807 11.4607 14.5147 11.367 14.4212L6.87276 9.927C6.73442 9.7885 6.66359 9.61441 6.66026 9.40475C6.65709 9.19525 6.72792 9.018 6.87276 8.873C7.01776 8.72816 7.19342 8.65575 7.39976 8.65575C7.60609 8.65575 7.78176 8.72816 7.92676 8.873L11.9998 12.9462L16.0728 8.873C16.2113 8.73466 16.3853 8.66383 16.595 8.6605C16.8045 8.65733 16.9818 8.72816 17.1268 8.873C17.2716 9.018 17.344 9.19366 17.344 9.4C17.344 9.60633 17.2716 9.782 17.1268 9.927L12.6325 14.4212C12.5388 14.5147 12.4401 14.5807 12.3363 14.6192C12.2324 14.6577 12.1203 14.677 11.9998 14.677Z"
                  fill="#030712"/>
              </svg>
            </button>
          </h2>

          <div class="dropdown">
            <div class="dropdown__content">
              {{ product.short_description }}
            </div>
          </div>
        </accordion-component>
      {% endif %}

      {% for item in lists.product-accordions.rows %}
        <accordion-component class="border-top-1--soft d-block">
          <h2 class="padding-y-200">
            <button type="button" class="clear-button padding-x-0 w-100 justify-content-between fw-regular">
              {{ item.title }}
              <svg class="rotate" xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24"
                   fill="none">
                <path
                  d="M11.9998 14.677C11.8793 14.677 11.7671 14.6577 11.6633 14.6192C11.5594 14.5807 11.4607 14.5147 11.367 14.4212L6.87276 9.927C6.73442 9.7885 6.66359 9.61441 6.66026 9.40475C6.65709 9.19525 6.72792 9.018 6.87276 8.873C7.01776 8.72816 7.19342 8.65575 7.39976 8.65575C7.60609 8.65575 7.78176 8.72816 7.92676 8.873L11.9998 12.9462L16.0728 8.873C16.2113 8.73466 16.3853 8.66383 16.595 8.6605C16.8045 8.65733 16.9818 8.72816 17.1268 8.873C17.2716 9.018 17.344 9.19366 17.344 9.4C17.344 9.60633 17.2716 9.782 17.1268 9.927L12.6325 14.4212C12.5388 14.5147 12.4401 14.5807 12.3363 14.6192C12.2324 14.6577 12.1203 14.677 11.9998 14.677Z"
                  fill="#030712"/>
              </svg>
            </button>
          </h2>

          <div class="dropdown">
            <div class="dropdown__content">
              {{ item.content }}
            </div>
          </div>
        </accordion-component>
      {% endfor %}
    </accordion-group>
  </div>
  <div data-active-warehouse-id="{{ store.all_warehouses[0].id }}"></div>
</product-wrapper>