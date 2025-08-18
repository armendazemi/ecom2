<swiper-slider slides="1" slidesDesktop="2.5">
  <div class="swiper swiper-container custom-swiper-grid">
    <div class="custom-swiper-grid__title">
      {{ 'satisfaction-title' | global_editable: class: 'display-md-heading p-color-secondary d-flex flex-column row-gap-200' }}
    </div>
    <div class="swiper-wrapper custom-swiper-grid__slides">
      {% for testimonial in lists.testimonials.rows %}
        <div class="swiper-slide">
          <article
            class="testimonial-card d-flex flex-column row-gap-300 padding-300 padding-lg-400 bg-white h-100">
            <div class="testimonial-card__stars d-flex align-items-center column-gap-25">
              {% for i in (1..testimonial.stars) %}
                <svg xmlns="http://www.w3.org/2000/svg" width="24" height="25" viewBox="0 0 24 25" fill="none">
                  <path
                    d="M11.9996 17.6743L8.10939 20.0203C7.96439 20.105 7.81914 20.1406 7.67364 20.1271C7.52814 20.1136 7.39648 20.0646 7.27864 19.9801C7.16064 19.8954 7.06956 19.7848 7.00539 19.6483C6.94139 19.5118 6.93114 19.3608 6.97464 19.1953L8.00739 14.7781L4.57289 11.8051C4.44456 11.6936 4.36281 11.5644 4.32764 11.4176C4.29231 11.2707 4.30156 11.1281 4.35539 10.9896C4.40923 10.8512 4.48681 10.7382 4.58814 10.6503C4.68948 10.5625 4.82798 10.5051 5.00364 10.4781L9.53614 10.0821L11.2959 5.91083C11.3599 5.75566 11.457 5.64091 11.5871 5.56658C11.7173 5.49224 11.8548 5.45508 11.9996 5.45508C12.1445 5.45508 12.282 5.49224 12.4121 5.56658C12.5423 5.64091 12.6394 5.75566 12.7034 5.91083L14.4631 10.0821L18.9956 10.4781C19.1713 10.5051 19.3098 10.5625 19.4111 10.6503C19.5125 10.7382 19.5901 10.8512 19.6439 10.9896C19.6977 11.1281 19.707 11.2707 19.6716 11.4176C19.6365 11.5644 19.5547 11.6936 19.4264 11.8051L15.9919 14.7781L17.0246 19.1953C17.0681 19.3608 17.0579 19.5118 16.9939 19.6483C16.9297 19.7848 16.8386 19.8954 16.7206 19.9801C16.6028 20.0646 16.4711 20.1136 16.3256 20.1271C16.1801 20.1406 16.0349 20.105 15.8899 20.0203L11.9996 17.6743Z"
                    fill="#030712"/>
                </svg>
              {% endfor %}
            </div>
            <div class="testimonial-card__comment text-secondary">
              {{ testimonial.comment }}
            </div>

            <div class="display-xs fw-semi">
              {{ testimonial.name }}
            </div>
          </article>
        </div>
      {% endfor %}
    </div>
    <div
      class="custom-swiper-grid__controls d-flex align-items-center column-gap-150 padding-top-400">
      <div
        class="swiper-button-prev swiper-button-prev--chev-icon radius-full bg-overlay-white-60"></div>
      <div
        class="swiper-button-next swiper-button-next--chev-icon radius-full bg-overlay-white-60"></div>
    </div>
  </div>
</swiper-slider>