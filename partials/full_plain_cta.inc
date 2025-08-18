{% capture hasContent %}{{ 'cta-banner-plain' | append: fullPlainId | has_page_editable }}{% endcapture %}
{% if hasContent == "true" %}
  <section class="section-padding-large color-primary text-center {{ fullPlainClass | fallback: 'bg-brand-soft' }}">
    <div class="container">
      <div class="row justify-content-center">
        <div class="col-lg-8">
          <div class="">
            {{ 'cta-eyebrow-plain' | append: fullPlainId | page_editable: class: 'eyebrow display-subheading' }}
            {{ 'cta-banner-plain' | append: fullPlainId | page_editable: class: 'display-lg-heading heading-200-spacing cta-spacing-400 d-flex d-flex flex-column' }}
            {{ 'cta-banner-links-plain' | append: fullPlainId | page_editable: class: 'brand-buttons-primary-dark d-flex flex-wrap gap-150 margin-top-400' }}
          </div>
        </div>
      </div>
    </div>
  </section>
{% endif %}