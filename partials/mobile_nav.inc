<top-element>
  <modal-component
    aria-labeledby="main-menu-title"
    id="main-menu">
    <div class="main-menu--mobile padding-y-300 padding-x-150 padding-x-sm d-flex flex-column row-gap-lg">
      <h2 id="main-menu-title" class="visually-hidden">
        {{ "Menu" | t }}
      </h2>

      <nav>
        <ul>
          {% for menuGrp in lists.menu-configurator.rows %}
            {% assign layout = menuGrp.layout.type %}
            {% assign parentGroup = menuGrp.main_group[0] %}

            {% if menuGrp.has_dropdown %}
            {% endif %}

          {% endfor %}

          {% for page in site.all_pages %}
            {% if page.visible_menu? and page.parent_page == nil %}

              {% if page.children.size > 0 %}
                <accordion-group class="d-flex flex-column w-100">
                  <accordion-component>
                    <button type="button"
                            class="nav-button all-caps justify-content-start w-100  justify-content-start">
                      <span>{{ page.title }}</span>
                      <svg class="rotate ms-auto" xmlns="http://www.w3.org/2000/svg" width="24" height="24"
                           viewBox="0 0 24 24" fill="none">
                        <path
                          d="M11.25 4.5V16.627L5.55375 10.9307L4.5 12L12 19.5L19.5 12L18.4462 10.9307L12.75 16.627V4.5H11.25Z"
                          fill="#030712"/>
                      </svg>
                    </button>

                    <div class="dropdown padding-x-150">
                      <div class="padding-150 radius-sm bg-brand-soft">
                        {% for child in page.children %}
                          <a href="{{ child.url }}"
                             class="nav-button all-caps justify-content-start">{{ child.title }}</a>
                        {% endfor %}
                      </div>
                    </div>
                  </accordion-component>
                </accordion-group>
              {% else %}
                <a href="{{ page.url }}" class="nav-button all-caps justify-content-start">{{ page.title }}</a>
              {% endif %}
            {% endif %}
          {% endfor %}
        </ul>
      </nav>
    </div>
  </modal-component>
</top-element>