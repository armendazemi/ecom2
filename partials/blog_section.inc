<section class="blog-section section-padding-large">
  <div class="container">
    <div class="row justify-content-center margin-bottom-400 margin-bottom-lg-600">
      <div class="col-lg-8">
        {{ 'blog-section-title' | page_editable: class: 'display-lg-heading text-center p-color-secondary' }}
      </div>
    </div>

    <div class="row row-gap-400">
      {% for article in articles.all.3 %}
        {% assign blogImage = article.preview %}
        {% assign blogLink = article.url %}
        {% assign blogEyebrow = article.categories[0].name %}
        {% assign blogHeading = article.title %}
        {% assign blogText = article.preview_text %}
        <div class="col-lg-4">
          {% include 'blog_card' %}
        </div>
      {% endfor %}
    </div>

    <div class="row margin-top-400 margin-top-lg-600">
      <div class="col-12">
        <div class="blog-section__cta ">
          {{ 'blog-section-cta' | page_editable: class: 'brand-button-primary-editable mx-auto w-fit-content' }}
        </div>
      </div>
    </div>
  </div>
</section>
