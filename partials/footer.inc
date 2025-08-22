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
    <div class="row flex-column flex-xl-row section-padding-medium gap-600">
      <div class="col-xl-4 col-lg-6">
        <div class="d-flex flex-column row-gap-300">
          {% if lists.global-settings.rows[0].newsletter %}
            {% include 'newsletter_form' %}
          {% else %}
            {{ 'about-us-title' | global_editable: class: 'display-subheading-heading d-flex flex-column row-gap-200 p-color-secondary' }}
          {% endif %}
        </div>
      </div>

      <div class="col-lg">
        <div class="row row-gap-600">
          {% for i in (1..4) %}
            <div class="col-12 col-lg-6 col-xl">
              {{ 'footer-link-title-' | append: i | global_editable: class: 'display-subheading-heading footer-links d-flex flex-column row-gap-200' }}
            </div>
          {% endfor %}
        </div>
      </div>
    </div>

    <div class="row row-gap-400">
      <div class="divider"></div>
      <div class="col-12">
        <accordion-group class="d-flex align-items-center gap-150">

          {% include 'locale_changer' %}
          {% include 'currency_changer' %}
        </accordion-group>
      </div>

      <div class="col-12">
        <div class="row flex-column flex-lg-row align-items-center gap-300">
          <div class="col">
            <p class="text-primary text-sm all-caps">© {{ "now" | date: '%Y' }} {{ site.name }}</p>
          </div>
          {% if lists.footer-logos.rows.size > 0 %}
            <div class="col">
              <div class="d-flex flex-wrap justify-content-start justify-content-lg-end gap-150">
                {% for logo in lists.footer-logos.rows %}
                  <div class="footer-logo-wrapper" style="width: 46px">
                    <img class="object-fit-contain  radius-sm" src="{{ logo.icon }}" alt="{{ logo.name }}"
                         height="32" width="32" loading="lazy" decoding="async" fetchpriority="low">
                  </div>
                {% endfor %}
              </div>
            </div>
          {% endif %}
        </div>
      </div>

    </div>

  </div>
</footer>

{% include 'newsletter_modal' %}
</body>
</html>