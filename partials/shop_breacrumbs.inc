<section class="breadcrumbs padding-y-200">
  <div class="container">
    <div class="row">
      <nav class="col-12">
        <ul class="list-unstyled m-0 d-flex flex-row align-items-center gap-50 flex-wrap">
          <li class="d-flex align-items-center gap-50">
            <a class="breadcrumb-link text-primary"
               href="/{% if locale != "sv" %}{{ locale }}{% endif %}">{{ "Hem" }}</a>
            <span>/</span>
          </li>
          {% if group.id %}
            {% for ancestor in group.path %}
              {% if ancestor.visible and ancestor.id != group.id %}
                <li class="d-flex align-items-center gap-50">
                  <a href="{{ ancestor.url }}"
                     class="breadcrumb-link text-primary">{{ ancestor.name }}</a>

                  {% unless forloop.last %}
                    <span>/</span>
                  {% endunless %}
                </li>
              {% endif %}
            {% endfor %}

            <li class="d-flex align-items-center gap-50">
              <span
                class="breadcrumb-link text-primary active">{{ group.name }}</span>
            </li>
          {% endif %}

          {% if product.id %}
            {% for ancestor in product.groups.breadcrumbs_for_sortiment %}
              {% if ancestor.visible %}
                <li class="d-flex align-items-center gap-50">
                  <a href="{{ ancestor.url }}"
                     class="breadcrumb-link text-primary">{{ ancestor.name }}</a>
                  {% unless forloop.last %}
                    <span>/</span>
                  {% endunless %}
                </li>
              {% endif %}
            {% endfor %}
            <li class="d-flex align-items-center gap-50">
            <span
              class="breadcrumb-link text-primary active">{{ product.name }}</span>
            </li>
          {% endif %}
        </ul>
      </nav>
    </div>
  </div>
</section>