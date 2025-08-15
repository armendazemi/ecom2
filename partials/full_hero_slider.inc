{% assign currentDate = "now" | date %}
<section class="hero {{ currentDate }}">
  <swiper-slider slides="1" pagination=".swiper-pagination--white" autoplay="true" delay="5000" fade="true" loop="true">
    <div class="swiper swiper-container">
      <div class="swiper-wrapper">
        {% for item in lists.hero-slider-start.rows %}
          {% assign itemStartDate = item.start_date | date | fallback: "1900-01-01 00:00"%}
          {% assign itemEndDate = item.end_date | date | fallback: "2100-12-30 00:00" %}
          {% if itemStartDate < currentDate and itemEndDate > currentDate %}
            <div class="swiper-slide position-relative">
              <div class="hero__image-overlay position-absolute inset-0 alpha-neutral-400A"></div>
              <picture>
                <source
                  srcset="{{ item.background_image_mobile }}"
                  media="(max-width: 991px)"
                  type="image/webp"
                >
                <source
                  srcset="{{ item.background_image }}"
                  media="(min-width: 992px)"
                  type="image/webp"
                >
                <img
                  class="hero__image object-fit-cover"
                  src="{{ item.background_image_mobile }}"
                  height="720"
                  width="1440"
                  alt=""
                  {% if forloop.first %}
                    loading="eager"
                    fetchpriority="high"
                  {% else %}
                    loading="lazy"
                    fetchpriority="low"
                    decoding="async"
                  {% endif %}
                >
              </picture>
              <div class="container position-absolute top-50 start-50 translate-middle ">
                <div class="row justify-content-center align-items-center">
                  <div class="col-lg-8">
                    <div
                      class="hero__content d-flex flex-column row-gap-300 align-items-center justify-content-center h-100 text-center">
                      <span class="hero__eyebrow text-white all-caps text-sm">{{ item.eyebrow }}</span>
                      <h2 class="hero__title display-xxl text-white">{{ item.title }}</h2>
                      <p class="hero__subtitle text-white">{{ item.subtitle }}</p>
                      {% if item.button_text %}
                        <a href="{{ item.button_link }}" class="brand-button-primary--dark margin-top-100">
                          {{ item.button_text }}
                        </a>
                      {% endif %}
                    </div>
                  </div>
                </div>
              </div>
            </div>
          {% endif %}

        {% endfor %}
      </div>

      <div class="swiper-pagination swiper-pagination--white start-50 translate-middle">

      </div>
    </div>
  </swiper-slider>
</section>