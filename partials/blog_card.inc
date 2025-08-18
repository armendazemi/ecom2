<article class="blog-card">
  <a class="blog-card__link" href="{{ blogLink }}" aria-label="{{ "Läs mer om" | t }} {{ blogHeading }}">
    <div class="blog-card__image">
      <img src="{{ blogImage }}" alt="{{ blogHeading }}" loading="lazy" decoding="async" height="280" width="421">
    </div>
    <div class="blog-card__content">
      <span class="blog-card__eyebrow display-subheading">{{ blogEyebrow }}</span>
      <h3 class="blog-card__heading display-sm">{{ blogHeading }}</h3>
      <p class="blog-card__text">{{ blogText | strip_html | truncate: 90 }}</p>
    </div>
  </a>
</article>