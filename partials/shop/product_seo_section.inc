<section class="product-seo-section padding-bottom-600 padding-bottom-lg-1200">
  <div class="container">
    <div class="row row-gap-200 justify-content-center">
      <div class="col-lg-8 text-center">
        {% if admin %}
          <p class="text-campaign">{{ "Titel och synlig text här" | t }}</p>
        {% endif %}
        {{ 'product-seo' | global_editable: class: 'display-lg-heading p-color-secondary d-flex flex-column row-gap-200' }}
      </div>

      <div class="col-lg-8 text-center product-seo-section__hidden-content {% if admin %} show {% endif %}"
           inert
           id="product-seo-extra">
        {% if admin %}
          <p class="text-campaign">{{ "Dold text" | t }}</p>
        {% endif %}

        {{ 'product-seo-text' | global_editable: class: 'p-color-secondary' }}
      </div>

      <div class="col-lg-8">
        <div class="d-flex justify-content-center">

          <button type="button" class="neutral-button-primary" aria-expanded="false"
                  aria-controls="product-seo-extra">{{ "Visa mer" | t }}</button>
        </div>
      </div>
    </div>
  </div>
</section>


<script>
  document.addEventListener('DOMContentLoaded', () => {
    const button = document.querySelector('.product-seo-section button');
    const hiddenContent = document.querySelector('.product-seo-section__hidden-content');

    if (button && hiddenContent) {
      button.addEventListener('click', () => {
        const isExpanded = button.getAttribute('aria-expanded') === 'true';
        button.setAttribute('aria-expanded', String(!isExpanded));

        if (isExpanded) {
          button.textContent = '{{ "Visa mer" | t }}';
          shouldOpenElement(hiddenContent, false);

        } else {
          button.textContent = '{{ "Visa mindre" | t }}';
          shouldOpenElement(hiddenContent, true);
        }
      });
    }

    function shouldOpenElement (element, shouldOpen) {
      if (shouldOpen) {
        element.style.maxHeight = element.scrollHeight + 'px';
        element.classList.add('open');
        hiddenContent.removeAttribute('inert');
      } else {
        element.style.maxHeight = null;
        element.classList.remove('open');
        hiddenContent.setAttribute('inert', '');
      }
    }
  });
</script>