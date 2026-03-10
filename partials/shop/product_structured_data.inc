<script type="application/ld+json">
  {
  "@context": "https://schema.org",
  "@type": "Product",
  "@id": "{{ product.url }}",
  "url": "{{ product.url }}",
  "name": "{{ product.name }}",
  "description": "{{ product.short_description | strip_newlines | replace: "&nbsp;", " " | strip_html }}",
  "image": [
  "{{ product.first_image.medium }}"
  ],

  "sku": "{{ product.master.sku }}",
  "brand": {
    "@type": "Brand",
    "name": "{{ product.groups.child_for_brands.name }}"
  },
  "offers": {
  "@type": "AggregateOffer",
  "priceCurrency": "SEK",
  "lowPrice": "{{ product.master_or_variant.prices.current.amount }}",
  "highPrice": "{{ product.master_or_variant.prices.current.amount }}",
  "offerCount": {% if product.variants.size > 0 %}{{ product.variants.size }}{% else %}1{% endif %},
  "availability":"https://schema.org/{% if product.master_or_variant_in_stock.in_stock? %}InStock{% elsif product.master_or_variant.stock.backorderable %}BackOrder{% else %}OutOfStock{% endif %}",
    "offers": [
      {% if product.variants.size > 0 %}
        {% for variant in product.variants %}
          {
          "@type": "Offer",
          "sku": "{{ variant.sku }}",
          "price": "{{ variant.prices.current.amount }}",
          "priceCurrency": "SEK",
          "availability":"https://schema.org/{% if variant.stock.in_stock? %}InStock{% elsif variant.stock.backorderable %}BackOrder{% else %}OutOfStock{% endif %}",
          "url": "{{ product.url }}"
          }{% unless forloop.last %},{% endunless %}
        {% endfor %}
      {% else %}
        {
          "@type": "Offer",
          "sku": "{{ product.master_or_variant.sku }}",
          "price": "{{ product.master_or_variant.prices.current.amount }}",
          "priceCurrency": "SEK",
          "availability":"https://schema.org/{% if product.master_or_variant.stock.in_stock? %}InStock{% elsif product.master_or_variant.stock.backorderable %}BackOrder{% else %}OutOfStock{% endif %}",
          "url": "{{ product.url }}"
        }
        {% endif %}
      ]
    }
  }
</script>