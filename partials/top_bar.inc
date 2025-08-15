<section class="top-bar bg-brand-primary padding-y-150 d-none d-lg-block" style="height: 54px;">
  <div class="container">
    <div class="row align-items-center justify-content-center">
      <swiper-slider
        slides="1"
        autoplay="true"
        loop="true"
        speed="300"
        delay="5000"
        fade="false"
      >
        <div class="swiper swiper-container">
          <div class="swiper-wrapper">
            {% for item in lists.top-banner.rows %}
              <div class="swiper-slide">
                <div class="top-banner-item text-white text-center">
                  {{ item.content }}
                </div>
              </div>
            {% endfor %}

          </div>
        </div>
      </swiper-slider>
    </div>
  </div>
</section>
