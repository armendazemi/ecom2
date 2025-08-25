{% for prod in product_selection %}
  <div class="col-md-6 col-xl-4">
    {% include 'product_card_hover_flip' %}
  </div>
{% endfor %}

{% assign next_paginate_url = 'next' | paginate_url %}
{% assign previous_paginate_url = 'previous' | paginate_url %}

{% if next_paginate_url %}
  <div class="d-flex justify-content-center mt-400">
    <a class="btn btn--primary" href="{{ next_paginate_url }}">
      {{ 'Visa fler produkter' | t }}
    </a>
  </div>
{% endif %}


{% if previous_paginate_url %}
  <div class="d-flex justify-content-center mt-400">
    <a class="btn btn--primary" href="{{ previous_paginate_url }}">
      {{ 'Visa föregående produkter' | t }}
    </a>
  </div>
{% endif %}

{% assign per_page = 5 %}
{% assign total_pages = total_products | divided_by: per_page %}
{% assign rest = total_pages | modulo: per_page %}

{% if rest != 0 %}
  {% assign total_pages = total_pages | plus: 1 %}
{% endif %}

{{ "Sida 1 av " | t }} {{ total_pages }}