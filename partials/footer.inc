</main>
<footer class="section-padding-large bg-brand-accent">
  <div class="container">
    <div class="row">
      <div class="col-12">
        <div class="d-flex">
          <a href="/{{ locale }}" class="nav-logo d-block">
            <img src="{{ 'logo-black.svg' | asset_path }}" alt="{{ site.name }}" height="42" width="128">
          </a>
        </div>

        <div class="col-12">
          <div class="divider margin-top-300 margin-top-lg-400"></div>
        </div>
      </div>
    </div>
    <div class="row section-padding-medium gap-600">
      <div class="col-lg-4">
        <div class="d-flex flex-column row-gap-300">
          {% if lists.global-settings.rows[0].newsletter %}
            {% include 'newsletter_form' %}
          {% else %}
            {{ 'about-us-title' | global_editable: class: 'display-subheading-heading d-flex flex-column row-gap-200 p-color-secondary' }}
          {% endif %}
        </div>
      </div>

      {% for i in (1..4) %}
        <div class="col-12 col-lg">
          {{ 'footer-link-title-' | append: i | global_editable: class: 'display-subheading-heading footer-links d-flex flex-column row-gap-200' }}
        </div>
      {% endfor %}

    </div>
    <div class="col-12">
      <div class="divider"></div>
    </div>
  </div>
</footer>

{% include 'newsletter_modal' %}
</body>
</html>