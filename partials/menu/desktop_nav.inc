<nav class="col-auto ms-auto">
  <ul role="menu" class=" align-items-center column-gap-150 d-none d-lg-flex m-0 list-unstyled">
    {% for menuGrp in lists.menu-configurator.rows %}
      {% assign layout = menuGrp.layout.type %}
      {% assign parentGroup = menuGrp.main_group[0] %}
      {% if menuGrp.has_dropdown %}

        <li role="none" class="position-relative">
          <button role="menuitem"
                  type="button"
                  class="nav-button all-caps"
                  aria-haspopup="menu"
                  aria-expanded="false"
                  aria-controls="menu-drop-{{ forloop.index }}"
                  data-modal-element="#menu-drop-{{ forloop.index }}"
                  data-modal-action="open"
                  data-action-toggle="true"
                  data-modal-overlay="false"
                  data-z-index="1000"
                  data-z-element="header"
                  data-modal-hover-open="true"
                  data-follow-link="{{ parentGroup.url }}"
          >
            {{ parentGroup.name }}
            <svg class="rotate" xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 20 20"
                 fill="none">
              <path
                d="M9.99576 12.5016C9.90645 12.5016 9.8234 12.4856 9.74659 12.4535C9.66978 12.4214 9.5993 12.3733 9.53513 12.3093L5.67201 8.44597C5.55201 8.32597 5.49409 8.19597 5.49826 8.05597C5.50256 7.91611 5.56506 7.78576 5.68576 7.66493C5.80659 7.54423 5.93562 7.48389 6.07284 7.48389C6.21006 7.48389 6.33909 7.54423 6.45992 7.66493L9.99992 11.226L13.5608 7.66493C13.6762 7.54965 13.8039 7.4941 13.9439 7.49826C14.0837 7.50257 14.2141 7.56507 14.3349 7.68576C14.4556 7.8066 14.516 7.93562 14.516 8.07285C14.516 8.21007 14.4533 8.34104 14.3278 8.46576L10.4647 12.3093C10.395 12.3733 10.3217 12.4214 10.2449 12.4535C10.1681 12.4856 10.0851 12.5016 9.99576 12.5016Z"
                fill="#030712"/>
            </svg>
          </button>
          <!--- Modal menus --->
          <top-element>
            <modal-component class="menu-dropdown" id="menu-drop-{{ forloop.index }}">
              <div class="main-menu--desktop__dropdown layout-{{ layout }}">
                <div class="container">
                  <div class="row">
                    {% include 'desktop_sub_menus' %}
                  </div>
                </div>
              </div>
            </modal-component>
          </top-element>
        </li>

      {% else %}
        <li role="none">
          <a role="menuitem" href="{{ parentGroup.main }}" class="nav-button all-caps">{{ parentGroup.name }}</a>
        </li>
      {% endif %}
    {% endfor %}


    {% for page in site.all_pages %}
      {% if page.visible_menu? and page.parent_page == nil %}

        {% if page.children.size > 0 %}
          <li role="none" class="position-relative">
            <button type="button"
                    role="menuitem"
                    class="nav-item-wrapper nav-button all-caps"
                    aria-controls="page-menu-{{ forloop.index }}"
                    aria-haspopup="menu"
                    aria-expanded="false"
                    data-follow-link="{{ page.url }}">
              {{ page.title }}
              <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 20 20" fill="none">
                <path
                  d="M9.99576 12.5016C9.90645 12.5016 9.8234 12.4856 9.74659 12.4535C9.66978 12.4214 9.5993 12.3733 9.53513 12.3093L5.67201 8.44597C5.55201 8.32597 5.49409 8.19597 5.49826 8.05597C5.50256 7.91611 5.56506 7.78576 5.68576 7.66493C5.80659 7.54423 5.93562 7.48389 6.07284 7.48389C6.21006 7.48389 6.33909 7.54423 6.45992 7.66493L9.99992 11.226L13.5608 7.66493C13.6762 7.54965 13.8039 7.4941 13.9439 7.49826C14.0837 7.50257 14.2141 7.56507 14.3349 7.68576C14.4556 7.8066 14.516 7.93562 14.516 8.07285C14.516 8.21007 14.4533 8.34104 14.3278 8.46576L10.4647 12.3093C10.395 12.3733 10.3217 12.4214 10.2449 12.4535C10.1681 12.4856 10.0851 12.5016 9.99576 12.5016Z"
                  fill="#030712"/>
              </svg>
            </button>

            <ul role="menu" class="nav-item__dropdown list-unstyled" id="page-menu-{{ forloop.index }}">
              {% for child in page.children %}
                <li role="none">
                  <a role="menuitem" href="{{ child.url }}"
                     class="nav-button justify-content-start all-caps">{{ child.title }}</a>
                </li>
              {% endfor %}
            </ul>
          </li>
        {% else %}
          <li role="none">
            <a role="menuitem" href="{{ page.url }}" class="nav-button all-caps">{{ page.title }}</a>
          </li>
        {% endif %}
      {% endif %}
    {% endfor %}
  </ul>
</nav>



