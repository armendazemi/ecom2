{% assign menuLinksCount = layout | split: "x" %}
{% assign menuLinksCount = menuLinksCount[0] | plus: 0 %}

{% assign featuredImagesCount = layout | split: "x" %}
{% assign featuredImagesCount = featuredImagesCount[1] | minus: 1 %}

{% for count in (1..menuLinksCount) %}
  {% assign groupTitle = "group_title_" %}
  {% assign groups = "groups_" %}
  {% case count %}
    {% when 1 %}
      {% assign groupTitle = groupTitle | append: "one" %}
      {% assign groups = groups | append: "one" %}
    {% when 2 %}
      {% assign groupTitle = groupTitle | append: "two" %}
      {% assign groups = groups | append: "two" %}
    {% when 3 %}
      {% assign groupTitle = groupTitle | append: "three" %}
      {% assign groups = groups | append: "three" %}
    {% when 4 %}
      {% assign groupTitle = groupTitle | append: "four" %}
      {% assign groups = groups | append: "four" %}
  {% endcase %}

  <nav aria-label="{{ menuGrp[groupTitle] }}">
    <div class="main-menu--mobile_sub-heading">
      <h2 class="display-subheading margin-bottom-150">
        {{ menuGrp[groupTitle] }}
      </h2>

      <ul class="d-flex flex-column row-gap-150 align-items-start list-unstyled m-0 p-0" role="menu">
        {% for subGrp in menuGrp[groups] %}
          <li role="none">
            <a role="menuitem" href="{{ subGrp.url }}" class="menu-item ">
              {{ subGrp.name }}
            </a>
          </li>
        {% endfor %}
      </ul>
    </div>
  </nav>
{% endfor %}


{% if featuredImagesCount > 0 %}
  <div class="row row-cols-2 d-flex flex-wrap">
    {% for index in (0..featuredImagesCount) %}
      <div class="col">
        <div class="main-menu--mobile__featured-image-item">
          <a href="{{ menuGrp.featured_image_groups[index].url }}" class="menu-item d-flex flex-column row-gap-150">
            <img src="{{ menuGrp.featured_image_groups[index].image_url }}"
                 alt="{{ menuGrp.featured_image_groups[index].name }}" width="100%" height="100%"
                 class="object-fit-cover aspect-1" loading="lazy">
            <h2 class="display-subheading text-center">{{ menuGrp.featured_image_groups[index].name }}</h2>
          </a>
        </div>
      </div>
    {% endfor %}
  </div>
{% endif %}

