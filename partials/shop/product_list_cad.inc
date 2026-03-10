<div class="product-card-list position-relative">
  <div
    class="product-card-list__badges position-absolute top-0 start-0 d-flex flex-column row-gap-50 justify-content-start z-2">
    {%-comment-%} If newer than 30 days, show new badge {%-endcomment-%}
    {% assign today_ts = "now" | date: "%s" | plus: 0 %}
    {% assign available_ts = prod.available_on | date: "%s" | plus: 0 %}

    {%- comment -%} seconds difference {%- endcomment -%}
    {% assign diff = today_ts | minus: available_ts %}

    {%- comment -%} 30 days in seconds = 60*60*24*30 = 2592000 {%- endcomment -%}
    {% if diff < 2592000 and diff >= 0 %}
      <span class="default-badge bg-brand-bold">{{ "Nyhet" | t }}</span>
    {% endif %}

    {% if prod.prices.default.amount > prod.prices.current.amount %}
      <span class="default-badge bg-error-bold">{{ "Rea" | t }}</span>
    {% endif %}
  </div>
  <div class="d-flex flex-row column-gap-200 ">
    <div class="product-card-list__image-wrapper position-relative flex-shrink-0">
      <a class="text-decoration-none" href="{{ prod.url }}" aria-label="{{ "Gå till produkt" | t }} {{ prod.name }}">
        <img class="object-fit-cover aspect-1 product-card-list__image-front" src="{{ prod.first_image.medium }}"
             alt="{{ prod.name }}"
             height="160"
             width="160"
             decoding="async"
             loading="lazy">
      </a>
    </div>
    <div class="product-card-list__content flex-grow-1 ">
      <div class="left">
        <a class="text-decoration-none" href="{{ prod.url }}" aria-label="{{ "Gå till produkt" | t }} {{ prod.name }}">
          <div class="product-card-list__name fw-semi">{{ prod.name }}</div>
        </a>
        {% if prod.master.sku.size > 0 or prod.master.ean.size > 0 %}
          <div class="d-flex column-gap-150 text-secondary">
            {% if prod.master.sku.size > 0 %}
              <span>{{ "Artnr: " }}{{ prod.master.sku }}</span>
            {% endif %}

            {% if prod.master.ean.size > 0 %}
              <span>{{ "EAN: " }}{{ prod.master.ean }}</span>
            {% endif %}
          </div>
        {% endif %}
        <div class="padding-top-100">
          {{ prod.short_description | truncate: 150 }}
        </div>
      </div>

      <div class="right d-flex flex-column">
        <div class="product-card-list__price text-end">
          {% if prod.prices.default.amount > prod.prices.current.amount %}
            <span class="product-card-list__price--default text-error">
            {{ prod.prices.default.amount | currency: 0 }}
          </span>
            <span class="product-card-list__price--current">
            <s>{{ prod.prices.current.amount | currency: 0 }}</s>
          </span>
          {% else %}
            {{ prod.prices.current.amount | currency: 0 }}
          {% endif %}
        </div>
      </div>

      <div class="product-card-list__footer d-flex align-items-center mt-auto">
        <div class="product-card-list__stock">
          {% if prod.master.stock.in_stock? %}
            <svg xmlns="http://www.w3.org/2000/svg" width="8" height="8" viewBox="0 0 8 8" fill="none">
              <circle cx="4" cy="4" r="3" fill="#15803D"/>
            </svg>
            {{ prod.master.stock.available_quantity }}
          {% elsif prod.master.stock.backorderable %}
            <svg xmlns="http://www.w3.org/2000/svg" width="8" height="8" viewBox="0 0 8 8" fill="none">
              <circle cx="4" cy="4" r="3" fill="#ff7d13"/>
            </svg>
            {{ "Beställningsvara" | t }}
          {% else %}
            <svg xmlns="http://www.w3.org/2000/svg" width="8" height="8" viewBox="0 0 8 8" fill="none">
              <circle cx="4" cy="4" r="3" fill="#dc2626"/>
            </svg>
            {{ prod.master.stock.out_of_stock_message | t }}

          {% endif %}
        </div>
        <div class="product-card-list__actions ms-auto">
          <a href="{{ prod.url }}" class="brand-button-primary">{{ "Läs mer" | t }}</a>
        </div>
      </div>
    </div>
  </div>

</div>
