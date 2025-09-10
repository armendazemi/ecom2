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
          {% if page.id %}
            {% for ancestor in page.path %}
              {% if ancestor.visible_menu? %}
                <li class="d-flex align-items-center gap-50">
                  <a href="{{ ancestor.url }}"
                     class="breadcrumb-link text-primary">{{ ancestor.title }}</a>

                  {% unless forloop.last %}
                    <span>/</span>
                  {% endunless %}
                </li>
              {% endif %}
            {% endfor %}

            <li class="d-flex align-items-center gap-50">
              <span
                class="breadcrumb-link text-primary active">{{ page.title }}</span>
            </li>
          {% endif %}


          {% if article.id %}
            <li class="d-flex align-items-center gap-50">
              <a href="{% if locale != "sv" %}/{{ locale }}{% endif %}/nyhetsarkiv"
                 class="breadcrumb-link text-primary">{{ "Nyhetsarkiv" }}</a>
              {% unless forloop.last %}
                <span>/</span>
              {% endunless %}
            </li>

            <li class="d-flex align-items-center gap-50">
              <span
                class="breadcrumb-link text-primary active">{{ article.title }}</span>
            </li>
          {% endif %}
        </ul>
      </nav>
    </div>
  </div>
</section>