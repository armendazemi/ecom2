{% if product.relation_also-like.size > 0 %}
  <section class="recommended-products padding-y-600 padding-y-lg-1200 bg-brand-accent">
    <div class="container">
      <div class="row justify-content-center">
        <div class="col-lg-8 text-center">
          {{ 'also-like-text' | global_editable: class: 'display-lg-heading p-color-secondary d-flex flex-column row-gap-200' }}
        </div>
      </div>

      <swiper-slider
        slides="1.2"
        slidesDesktop="3"
        class="d-block margin-top-400 margin-top-lg-600">
        <div class="swiper swiper-container">
          <div class="swiper-wrapper">
            {% for prod in product.relation_also-like %}
              <div class="swiper-slide padding-25">
                {% include 'product_card_hover_flip' %}
              </div>
            {% endfor %}
          </div>
        </div>
      </swiper-slider>
    </div>
  </section>
{% endif %}