<article class="product-card-flip position-relative">
  <div
    class="product-card-flip__badges position-absolute top-0 start-0 d-flex flex-column row-gap-50 justify-content-start z-2">
    {%-comment-%} If newer than 30 days, show new badge {%-endcomment-%}
    {% assign today_ts = "now" | date: "%s" | plus: 0 %}
    {% assign available_ts = prod.available_on | date: "%s" | plus: 0 %}

    {%- comment -%} seconds difference {%- endcomment -%}
    {% assign diff = today_ts | minus: available_ts %}

    {%- comment -%} 30 days in seconds = 60*60*24*30 = 2592000 {%- endcomment -%}
    {% if diff < 2592000 and diff >= 0 %}
      <span class="default-badge bg-brand-bold">New</span>
    {% endif %}

    {% if prod.prices.default.amount > prod.prices.current.amount %}
      <span class="default-badge bg-error-bold">Sale</span>
    {% endif %}
  </div>
  <a class="d-flex flex-column row-gap-200 text-decoration-none" href="{{ prod.url }}"
     aria-label="{{ "Gå till product" | t }} {{ prod.name }}">
    <div class="product-card-flip__image-wrapper position-relative">
      <img class="object-fit-contain aspect-1 product-card-flip__image-front" src="{{ prod.first_image.medium }}" alt=""
           height="416"
           width="416"
           decoding="async"
           loading="lazy">

      {% if prod.images[1].medium %}
        <img class="object-fit-contain aspect-1 product-card-flip__image-back close" src=""
             height="416"
             width="416"
             data-src="{{ prod.images[1].medium }}" alt=""
             decoding="async"
             loading="lazy">
      {% endif %}
    </div>

    <div class="product-card-flip__body d-flex flex-column row-gap-50 align-items-center">
      <h3 class="text-md fw-medium family-body">{{ prod.name }}</h3>

      <div class="product-card-flip__price">
        {% if prod.prices.default.amount > prod.prices.current.amount %}
          <span class="product-card-flip__price--default text-error">
            {{ prod.prices.default.amount | currency: 0 }}
          </span>
          <span class="product-card-flip__price--current">
            <s>{{ prod.prices.current.amount | currency: 0 }}</s>
          </span>
        {% else %}
          {{ prod.prices.current.amount | currency: 0 }}
        {% endif %}
      </div>
    </div>
  </a>
</article>

{% assign isVariant = false %} <!--- Reset --->