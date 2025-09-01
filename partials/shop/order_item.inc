<article class="order-item d-flex column-gap-200 padding-bottom-300 border-bottom-1--soft"
         data-variant-id="{{ item.variant.id }}">
  <div class="order-item__image flex-shrink-0">
    <img class="object-fit-cover aspect-1" src="{{ item.variant.first_image.small }}" alt="{{ item.title }}"
         width="144" height="144">
  </div>
  <div class="order-item__body d-flex flex-column row-gap-50 flex-grow-1 flex-shrink-0">
    <a href="{{ item.product.url }}" class="order-item__name fw-semi text-decoration-none">{{ item.name }}</a>

    {% if item.product.properties.size > 0 or item.variant.option_values.size > 0 %}
      <div class="order-item__properties text-sm text-secondary">
        {% for prop in item.product.properties %}
          {% if prop.option_category.name contains "Display" %}
            <span class="text-sm text-secondary">{{ prop.value }}</span>
          {% endif %}
        {% endfor %}

        {% for value in item.variant.option_values %}
          <span class="text-sm text-secondary">{{ value.presentation }}</span>
        {% endfor %}
      </div>
    {% endif %}

    <div class="order-item__price w-100 d-flex column-gap-150">
      {% if item.variant.prices.default.amount > item.variant.prices.current.amount %}
        <p
          class="order-item__price text-decoration-line-through">{{ item.variant.prices.default.amount | currency: 0 }}</p>
        <p
          class="order-item__price text-campaign ">
          {{ item.variant.prices.current.amount | currency: 0 }}
        </p>
      {% else %}
        <p
          class="order-item__price">{{ item.variant.prices.current.amount | currency: 0 }}</p>
      {% endif %}
    </div>

    <div class="order-item__footer d-flex column-gap-150">
                  <span
                    class="order-item__quantity text-sm text-secondary">{{ "Antal" | t }}: {{ item.quantity }}</span>

      <button type="button" class="brand-link remove-variant ms-auto"k
              data-variant-id="{{ item.variant.id }}">{{ "Ta bort" | t }}</button>
    </div>
  </div>
</article>