<script type="application/ld+json">
  {
    "@context": "https://schema.org",
    "@type": "CollectionPage",
    "@id": "{{ request.base_url }}{% if locale != "sv" %}/{{ locale }}{% endif %}{{ group.url }}",
    "url": "{{ request.base_url }}{% if locale != "sv" %}/{{ locale }}{% endif %}{{ group.url }}",
    "name": "{{ group.name }}",
    "description": "{{ group.description | strip_newlines | replace: "&nbsp;", " " | strip_html }}",
    "mainEntity": {
      "@type": "ItemList",
      "name": "{{ group.name }}",
      "itemListOrder": "https://schema.org/ItemListOrderAscending",
      "numberOfItems": {{ product_selection.size }},
      "itemListElement": [{% for product in product_selection %}
        {
          "@type": "ListItem",
          "position": {{ forloop.index }},
          "url": "{{ product.url }}"
        }{% unless forloop.last %},{% endunless %}
  {% endfor %}]
    }
  }
</script>
