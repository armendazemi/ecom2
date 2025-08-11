<nav class="col-auto ms-auto">
  <ul class=" align-items-center column-gap-150 d-none d-lg-flex m-0 list-unstyled">
    {% for menuGrp in groups.all %}
      {% assign showGrp = false %}
      {% for tag in menuGrp.tags %}
        {% if tag.name == "menu" %}
          {% assign showGrp = true %}
        {% endif %}
      {% endfor %}

      {% if showGrp %}
        {% if menuGrp.children.size > 0 %}
          <accordion-group>
            <li class="position-relative">
              <accordion-component>
                <button type="button" aria-haspopup="menu" class="nav-button all-caps">
                  {{ menuGrp.name }}
                  <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 20 20" fill="none">
                    <path d="M9.99576 12.5016C9.90645 12.5016 9.8234 12.4856 9.74659 12.4535C9.66978 12.4214 9.5993 12.3733 9.53513 12.3093L5.67201 8.44597C5.55201 8.32597 5.49409 8.19597 5.49826 8.05597C5.50256 7.91611 5.56506 7.78576 5.68576 7.66493C5.80659 7.54423 5.93562 7.48389 6.07284 7.48389C6.21006 7.48389 6.33909 7.54423 6.45992 7.66493L9.99992 11.226L13.5608 7.66493C13.6762 7.54965 13.8039 7.4941 13.9439 7.49826C14.0837 7.50257 14.2141 7.56507 14.3349 7.68576C14.4556 7.8066 14.516 7.93562 14.516 8.07285C14.516 8.21007 14.4533 8.34104 14.3278 8.46576L10.4647 12.3093C10.395 12.3733 10.3217 12.4214 10.2449 12.4535C10.1681 12.4856 10.0851 12.5016 9.99576 12.5016Z" fill="#030712"/>
                  </svg>
                </button>

                <div class="dropdown menu-dropdown position-absolute" role="menu">
                  <ul class="d-flex flex-column row-gap- list-unstyled  padding-x-300 padding-y-150"
                      role="none">
                    {% for child in menuGrp.children %}
                      <li role="none">
                        <a role="menuitem" href="{{ child.url }}"
                           class="nav-button justify-content-start all-caps">{{ child.name }}</a>
                      </li>
                    {% endfor %}
                  </ul>
                </div>
              </accordion-component>
            </li>
          </accordion-group>
        {% else %}
          <li>
            <a href="{{ menuGrp.url }}" class="nav-button all-caps">{{ menuGrp.name }}</a>
          </li>
        {% endif %}
      {% endif %}
    {% endfor %}


    {% for page in site.all_pages %}
      {% if page.visible_menu? and page.parent_page == nil %}

        {% if page.children.size > 0 %}
          <li>
            <div class="nav-item-wrapper position-relative"
                 tabindex="0"
                 role="button"
                 aria-haspopup="true"
                 aria-expanded="false">
              <div class="nav-button all-caps">
                {{ page.title }}
                <svg class="rotate" xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 20 20"
                     fill="none">
                  <path
                    d="M9.45817 4.4165V13.5015L5.19046 9.2338L4.4165 9.99984L9.99984 15.5832L15.5832 9.99984L14.8092 9.2338L10.5415 13.5015V4.4165H9.45817Z"
                    fill="#030712"/>
                </svg>
              </div>
              <div class="nav-item__dropdown">
                {% for child in page.children %}
                  <a href="{{ child.url }}"
                     class="nav-button all-caps">{{ child.title }}</a>
                {% endfor %}
              </div>
            </div>
          </li>
        {% else %}
          <a href="{{ page.url }}" class="nav-button all-caps">{{ page.title }}</a>
        {% endif %}
      {% endif %}
    {% endfor %}
  </ul>
</nav>



