{% include 'header' %}
<h1 class="visually-hidden">{{ "SEO titel startsida" | t }}</h1>

{% include 'full_hero_slider' %}

<section class="section-padding-large">
  <div class="container">
    <div class="row justify-content-center">
      <div class="col-lg-8">
        {{ 'product-feature-title' | page_editable: class: 'd-flex flex-column row-gap-200 justify-content-center text-center display-xl-heading p-color-secondary' }}
      </div>
    </div>

    <div class="row margin-top-400 margin-top-lg-600 row-gap-400">
      {% for var in lists.featured-products-start.rows[0].products %}
        <div class="col-lg-4">
          {% assign prod = var.product %}
          {% include 'product_card_hover_flip' %}
        </div>
      {% endfor %}
    </div>
  </div>
</section>

{% assign fullImageId = 1 %}
{% assign centerImageLayout = true %}
{% include 'full_image_bg_cta' %}

{% capture hasContent %}{{ 'collections-title' | has_page_editable }}{% endcapture %}
{% if hasContent == 'true' %}
  <section class="section-padding-large">
    <div class="container">
      <div class="row justify-content-center">
        <div class="col-lg-6">
          {{ 'collections-title' | page_editable: class: 'display-xl-heading text-subheading-p d-flex flex-column row-gap-200 align-items-center' }}
        </div>
      </div>
    </div>
  </section>
{% endif %}

{% assign fullImageId = 2 %}
{% include 'full_image_bg_cta' %}


{% if lists.testimonials.rows.size > 0 %}
  <section class="section-padding-large customer-satisfaction bg-brand-soft">
    <div class="container">
      {% include 'customer_reviews_slider' %}
    </div>
  </section>
{% endif %}


{% if articles.all.size > 0 %}
  {% include 'blog_section' %}
{% endif %}

{% if lists.uspar-start.rows.size > 0 %}
  <section class="section-padding-large bg-brand-bold">
    <h2 class="visually-hidden">{{ "Varför du ska handla hos oss" | t }}</h2>
    <div class="container">
      <div class="row row-gap-400">
        {% for usp in lists.uspar-start.rows %}
          <div class="col-lg">
            <div class="usp-item d-flex text-white text-center flex-column justify-content-center row-gap-200">
              <div class="usp-item__icon">
                <img src="{{ usp.icon }}" alt=" " height="32" width="32">
              </div>
              <h3 class="display-xxs">{{ usp.title }}</h3>
              {{ usp.description }}
            </div>
          </div>
        {% endfor %}
      </div>
    </div>
  </section>
{% endif %}

{% if lists.featured-in-images.rows.size > 0 %}
  {% include 'featured_images_section' %}
{% endif %}

{% assign fullPlainClass = "bg-brand-soft" %}
{% assign fullPlainId = 1 %}
{% include 'full_plain_cta' %}


{% include 'footer' %}