{% if page.id %}
  {% capture imageSource %}
    {{ 'cta-banner-image-' | append: fullImageId | page_editable }}
  {% endcapture %}

  {% assign imageSource = imageSource | split: 'src="' %}
  {% assign imageSource = imageSource[1] | replace: "/>", "" | replace: '"', "" | strip_html %}

  {% capture hasContent %}{{ 'cta-banner' | append: fullImageId | has_page_editable }}{% endcapture %}
  {% if hasContent == 'true' %}
    <section class="section-padding-large"
    {% if admin %}
      style="background: linear-gradient(0deg, rgba(3, 7, 18, 0.50) 0%, rgba(3, 7, 18, 0.50) 100%), url({{ nothing }}) lightgray 50% / cover no-repeat;"
    {% else %}
      style="background: linear-gradient(0deg, rgba(3, 7, 18, 0.50) 0%, rgba(3, 7, 18, 0.50) 100%), url({{ imageSource }}) lightgray 50% / cover no-repeat;"
      {% endif %}>
      <div class="container">
        <div class="row {% if centerImageLayout %} justify-content-center {% endif %}">
          <div class="col-lg-6 {% if centerImageLayout %} d-flex flex-column align-items-center text-center{% endif %}">
            {{ 'cta-eyebrow' | append: fullImageId |page_editable: class: 'eyebrow text-white display-subheading' }}
            {{ 'cta-banner' | append: fullImageId |page_editable: class: 'display-lg-heading heading-200-spacing cta-spacing-400 d-flex d-flex flex-column text-white' }}
            {{ 'cta-banner-links' | append: fullImageId |page_editable: class: 'brand-buttons-primary-dark d-flex flex-wrap gap-150 margin-top-400' }}
          </div>

          {% if admin %}
            <div class="col-lg-6">
              <div class="d-flex flex-column row-gap-200">
                {{ 'cta-banner-image-' | append: fullImageId | page_editable }}
                <p class="subtitle-1 text-white">This image will replace the background once outside of editmode.</p>
              </div>
            </div>
          {% endif %}
        </div>
      </div>
    </section>
  {% endif %}

{% else %} <!--- For products.ws --->

  {% capture imageSource %}
    {{ 'cta-banner-image' | global_editable }}
  {% endcapture %}

  {% assign imageSource = imageSource | split: 'src="' %}
  {% assign imageSource = imageSource[1] | replace: "/>", "" | replace: '"', "" | strip_html %}

  {% capture hasContent %}{{ 'cta-banner' | has_global_editable }}{% endcapture %}
  {% if hasContent == 'true' %}

    <section class="section-padding-large"
    {% if admin %}
      style="background: linear-gradient(0deg, rgba(3, 7, 18, 0.50) 0%, rgba(3, 7, 18, 0.50) 100%), url({{ nothing }}) lightgray 50% / cover no-repeat;"
    {% else %}
      style="background: linear-gradient(0deg, rgba(3, 7, 18, 0.50) 0%, rgba(3, 7, 18, 0.50) 100%), url({{ imageSource }}) lightgray 50% / cover no-repeat;"
      {% endif %}>
      <div class="container">
        <div class="row {% if centerImageLayout %} justify-content-center {% endif %}">
          <div class="col-lg-6 {% if centerImageLayout %} d-flex flex-column align-items-center text-center{% endif %}">
            {{ 'cta-eyebrow' | global_editable: class: 'eyebrow text-white display-subheading' }}
            {{ 'cta-banner' | global_editable: class: 'display-lg-heading heading-200-spacing cta-spacing-400 d-flex d-flex flex-column text-white' }}
            {{ 'cta-banner-links' | global_editable: class: 'brand-buttons-primary-dark d-flex flex-wrap gap-150 margin-top-400' }}
          </div>

          {% if admin %}
            <div class="col-lg-6">
              <div class="d-flex flex-column row-gap-200">
                {{ 'cta-banner-image' | page_editable }}
                <p class="subtitle-1 text-white">This image will replace the background once outside of editmode.</p>
              </div>
            </div>
          {% endif %}
        </div>
      </div>
    </section>
  {% endif %}
{% endif %}

{% assign centerImageLayout = false %} <!--- Reset --->
