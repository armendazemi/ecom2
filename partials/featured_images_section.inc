<section class="section-padding-large feature-section">
  <div class="container">
    <div class="row justify-content-center row-gap-300 row-gap-lg-400">
      <div class="col-lg-8">
        {{ 'feature-section-title' | page_editable: class: 'display-md-heading p-color-secondary d-flex flex-column row-gap-200 text-center' }}
      </div>
      <div class="col-12">
        <div class="row align-items-center row-gap-300">
          {% for item in lists.featured-in-images.rows %}
            <div class="col-6 col-lg">
              <div class="feature-item">
                <img src="{{ item.image }}" alt="{{ item.name }}" class="object-fit-contain" loading="lazy"
                     decoding="async">
              </div>
            </div>
          {% endfor %}
        </div>
      </div>
    </div>
  </div>
</section>
