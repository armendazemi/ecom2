<nav class="bg-white padding-y-200">
  <div class="container">
    <div class="row align-items-center">
      <div class="col-auto">
        <a href="/{{ locale }}" class="nav-logo d-block">
          <img src="{{ 'logo-black.svg' | asset_path }}" alt="{{ site.name }}" height="42" width="128">
        </a>
      </div>

      {% include 'desktop_nav' %}


      <div class="col-auto ms-auto">
        <div class="d-flex align-items-center">
          {% include 'menu_cta_items' %}
          {% include 'mobile_menu_toggle' %}
        </div>
      </div>
    </div>
  </div>
</nav>

{% include 'search_modal' %}
{% include 'mobile_nav' %}