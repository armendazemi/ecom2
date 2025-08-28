{% for prod in product_selection %}
  <div class="col-md-6 col-xl-4">
    {% include 'product_card_hover_flip' %}
  </div>
{% endfor %}

{% assign next_paginate_url = 'next' | paginate_url %}
{% assign previous_paginate_url = 'previous' | paginate_url %}


{% assign per_page = 8 %}
{% assign total_pages = total_products | divided_by: per_page %}
{% assign rest = total_pages | modulo: per_page %}

{% if rest != 0 %}
  {% assign total_pages = total_pages | plus: 1 %}
{% endif %}


{% if total_pages > 1 %}
  <div class="pagination d-flex align-items-center justify-content-end column-gap-150 margin-top-400">
    {{ "Sida" | t }} {{ request.params.page | fallback: 1 }} {{ "av" | t }} {{ total_pages }}

    {% if previous_paginate_url %}
      <a class="brand-button-secondary" href="{{ previous_paginate_url }}">
        <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 20 20" fill="none">
          <path
            d="M11.9995 14.7114L7.28809 9.99997L11.9995 5.28851L12.7735 6.06247L8.836 9.99997L12.7735 13.9375L11.9995 14.7114Z"
            fill="#030712"/>
        </svg>
      </a>
    {% else %}
      <a class="neutral-button-primary ">
        <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 20 20" fill="none">
          <path
            d="M11.9995 14.7114L7.28809 9.99997L11.9995 5.28851L12.7735 6.06247L8.836 9.99997L12.7735 13.9375L11.9995 14.7114Z"
            fill="#030712"/>
        </svg>
      </a>
    {% endif %}

    {% if next_paginate_url %}
      <a class="brand-button-secondary" href="{{ next_paginate_url }}">
        <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 20 20" fill="none">
          <path
            d="M11.1631 9.99997L7.22559 6.06247L7.99954 5.28851L12.711 9.99997L7.99954 14.7114L7.22559 13.9375L11.1631 9.99997Z"
            fill="#030712"/>
        </svg>

      </a>
    {% else %}
      <a class="brand-button-secondary disabled">
        <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 20 20" fill="none">
          <path
            d="M11.1631 9.99997L7.22559 6.06247L7.99954 5.28851L12.711 9.99997L7.99954 14.7114L7.22559 13.9375L11.1631 9.99997Z"
            fill="#030712"/>
        </svg>

      </a>
    {% endif %}
  </div>

{% endif %}


