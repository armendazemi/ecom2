{% if lists.product-faq.rows.size > 0 %}
  <section class="section-padding-large">
    <div class="container">
      <div class="row justify-content-center">
        <div class="col-lg-8 text-center">
          {{ 'product-faq' | global_editable: class: 'display-lg-heading p-color-secondary d-flex flex-column row-gap-200' }}
        </div>

        <div class="row margin-top-600 margin-top-lg-400 justify-content-center">
          <accordion-group class="border-bottom-1--soft col-lg-8">
            {% for faq in lists.product-faq.rows %}
              <accordion-component class="border-top-1--soft d-block">
                <h3 class="padding-y-200">
                  <button type="button" class="clear-button padding-x-0 w-100 justify-content-between fw-regular">
                    {{ faq.question }}
                    <svg class="rotate" xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24"
                         fill="none">
                      <path
                        d="M11.9998 14.677C11.8793 14.677 11.7671 14.6577 11.6633 14.6192C11.5594 14.5807 11.4607 14.5147 11.367 14.4212L6.87276 9.927C6.73442 9.7885 6.66359 9.61441 6.66026 9.40475C6.65709 9.19525 6.72792 9.018 6.87276 8.873C7.01776 8.72816 7.19342 8.65575 7.39976 8.65575C7.60609 8.65575 7.78176 8.72816 7.92676 8.873L11.9998 12.9462L16.0728 8.873C16.2113 8.73466 16.3853 8.66383 16.595 8.6605C16.8045 8.65733 16.9818 8.72816 17.1268 8.873C17.2716 9.018 17.344 9.19366 17.344 9.4C17.344 9.60633 17.2716 9.782 17.1268 9.927L12.6325 14.4212C12.5388 14.5147 12.4401 14.5807 12.3363 14.6192C12.2324 14.6577 12.1203 14.677 11.9998 14.677Z"
                        fill="#030712"/>
                    </svg>
                  </button>
                </h3>
                <div class="dropdown">
                  <div class="dropdown__content">
                    {{ faq.answer }}
                  </div>
                </div>
              </accordion-component>
            {% endfor %}
          </accordion-group>
        </div>
      </div>
    </div>
  </section>
{% endif %}