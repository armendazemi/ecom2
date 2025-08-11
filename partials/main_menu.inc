<nav class="bg-white padding-y-200">
  <div class="container">
    <div class="row align-items-center">
      <div class="col-auto">
        <a href="/{{ locale }}" class="nav-logo d-block">
          <img src="{{ 'logo-black.svg' | asset_path }}" alt="{{ site.title }}" height="42" width="128">
        </a>
      </div>

      {% include 'desktop_nav' %}

      <div class="col-auto d-flex align-items-center column-gap-150 ms-auto">
        {% include 'language_selector' %}
        {% include 'mobile_menu_toggle' %}
      </div>
    </div>
  </div>
</nav>

{% include 'mobile_nav' %}