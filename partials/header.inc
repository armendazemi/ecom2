<!DOCTYPE html>
<html lang="{{ locale }}">
<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge"/>
  <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">

  <title>{{ title | t | fallback: seo.title }} {% if request.params.page %} | {{ "Sida" | t }} {{ request.params.page }}{% endif %}</title>
  <meta name="description" content="{{ seo.description | fallback: "Fokus, Sveriges största webbutik" | t }}">
  <meta name="keywords" content="{{ seo.keywords }}">

  <meta property="og:title" content="{{ page.title }}"/>
  <meta property="og:description" content="{{ page.og_description }}"/>
  <meta property="og:image" content="{{ page.og_image }}"/>

  {% assign is_no_duplicate = false %}

  {% if locale == site.default_locale %}
    {% if request.path == '/sv' or request.path == '/sv/' %}
      {% assign is_no_duplicate = true %}
    {% endif %}
  {% endif %}

  {% comment %} --- NOINDEX handling. --- {% endcomment %}
  {% if is_no_duplicate %}
    <meta name="robots" content="noindex,follow">
  {% endif %}

  {% if locale == "sv" %}
    <link href="{{ request.base_url }}{{ request.path }}" rel="canonical">
  {% else %}
    <link href="{{ request.base_url }}/{{ locale }}{{ request.path }}" rel="canonical">
  {% endif %}

  {% for locale in site.locales %}
    {% if locale != site.default_locale %}
      <link rel="alternate" hreflang="{{ locale }}"
            href="{{ request.base_url }}/{{ locale }}{{ request.path }}{% if request.params.page %}?page={{ request.params.page }}{% endif %}"/>
    {% endif %}
  {% endfor %}

  <link rel="alternate" hreflang="{{ site.default_locale }}"
        href="{{ request.base_url }}{{ request.path }}{% if request.params.page %}?page={{ request.params.page }}{% endif %}"/>
  <link rel="alternate" hreflang="x-default" href="{{ request.base_url }}/">

  <link rel="icon" href="{{ 'favicon.png' | asset_path }}">


  {{ wm3 }}
  {{ wm3_public_ecom_javascript }}

  <link rel="alternate" type="application/rss+xml" href="/{{ locale }}/a.rss" title="RSS Feed">
  <!--- Preload the first hero mobile image to improve mobile performance --->
  <link rel="preload" as="image" href="{{ lists.hero-slider-start.rows[0].background_image_mobile }}" type="image/webp"
        fetchpriority="high">

  {% assign version = "version=1.0" %}

  <!--- Preloads --->
  <link rel="reload" as="image" href="{{ lists.hero-slider-start.rows[0].background_image_mobile }}">
  <link rel="preload" as="style" href="{{ 'styles.css' | template_path }}?{{ version }}">
  <link rel="preconnect" href="https://fonts.googleapis.com">
  <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>


  <!-- Fonts & Icons -->
  <link
    href="https://fonts.googleapis.com/css2?family=Instrument+Sans:ital,wght@0,100;0,200;0,300;0,400;0,500;0,600;0,700;1,100;1,200;1,300;1,400;1,500;1,600;1,700&family=Barlow:ital,wght@0,100;0,200;0,300;0,400;0,500;0,600;0,700;1,100;1,200;1,300;1,400;1,500;1,600;1,700&display=swap"
    rel="stylesheet">

  <!--- Styles --->
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/swiper@11/swiper-bundle.min.css"/>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.7/dist/css/bootstrap.min.css" rel="stylesheet"
        integrity="sha384-LN+7fdVzj6u52u30Kp6M/trliBMCMKTyK833zpbD+pXdCLuTusPj697FH4R/5mcr" crossorigin="anonymous">


  <link href="{{ 'styles.css' | template_path }}?{{ version }}" rel="stylesheet">


  <!---- Scripts --->
  <script src="{{ 'cart_tracker.js' | template_path }}?{{ version }}" defer></script>
  <script src="{{ 'common.js' | template_path }}?{{ version }}" defer></script>
  <script src="{{ 'locale_changer.component.js' | template_path }}?{{ version }}" async></script>
  <script src="https://cdn.jsdelivr.net/npm/swiper@11/swiper-bundle.min.js"></script>

  {% assign invoiceName = "Faktura" %}


  <script>
    window.showTaxes = {{ customer.show_taxes }};
    window.locale = '{{ locale }}';
    window.shopCountry = '{{ store.country.iso_name }}';
    window.shopCurrency = '{{ store.currency.name }}';

    window.translations = {{ site.translations | jsonify }};
    window.currencySymbol = "{{ store.currency.symbol }}";

    window.getTranslation = (key) => {
      return window.translations[key] || key;
    };

    window.hasRecaptcha = {{ site.has_recaptcha_enabled }};
    window.recaptcha_public_key = "{{ site.recaptcha_public_key }}";
    const currency = window.shopCurrency;
    const uiLocale = window.locale;

    const currencyLocaleMap = {
      SEK: 'sv-SE',
      DKK: 'da-DK',
      NOK: 'nb-NO',
      EUR: 'de-DE'
    };

    window.ecomConfig = {
      priceCurrency: currency,
      priceLocale: currencyLocaleMap[currency] || (
        uiLocale === 'sv' ? 'sv-SE' :
          uiLocale === 'da' ? 'da-DK' :
            uiLocale === 'no' ? 'nb-NO' :
              uiLocale === 'fi' ? 'fi-FI' :
                'en-GB'
      ),
      priceMinDecimalDigits: 0,
      priceMaxDecimalDigits: 2
    };

  </script>


</head>
<body class="">
<a href="#main-content" class="brand-button-primary w-fit-content"
   id="skip-link">{{ "Hoppa till huvudinnehåll" | t }}</a>

<header class="main-header">
  {% include 'top_bar' %}
  {% include 'main_menu' %}
</header>

<overlay-component></overlay-component>
<main id="main-content">


