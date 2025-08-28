<!DOCTYPE html>
<html lang="{{ locale }}">
<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge"/>
  <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">

  <title>{{ title | t | fallback: seo.title }} {%if request.params.page%} | {{"Sida"|t}} {{request.params.page}}{% endif %}</title>
  <meta name="description" content="{{ seo.description | fallback: "Fokus, Sveriges största webbutik" | t }}">
  <meta name="keywords" content="{{ seo.keywords }}">

  <meta property="og:title" content="{{ page.title }}"/>
  <meta property="og:description" content="{{ page.og_description }}"/>
  <meta property="og:image" content="{{ page.og_image }}"/>

  {% if locale == "sv" %}
    <link href="https://ecom2.se{{ request.path }}{%if request.params.page%}?page={{request.params.page}}{% endif %}" rel="canonical">
  {% elsif locale == "en" %}
    <link href="https://ecom2.se/en{{ request.path }}{%if request.params.page%}?page={{request.params.page}}{% endif %}" rel="canonical">
  {% endif %}
  <link rel="alternate" hreflang="sv" href="https://ecom2.se/"/>
  <link rel="alternate" hreflang="en" href="https://ecom2.se/en"/>

  <link rel="icon" href="{{ 'favicon.png' | asset_path }}">


  {{ wm3 }}
  {{ wm3_public_ecom_javascript }}

  <link rel="alternate" type="application/rss+xml" href="/{{ locale }}/a.rss" title="RSS Feed">
  <!--- Preload the first hero mobile image to improve mobile performance --->
  <link rel="preload" as="image" href="{{lists.hero-slider-start.rows[0].background_image_mobile}}" type="image/webp" fetchpriority="high">

  {% assign version = "version=1.0" %}

  <!--- Preloads --->
  <link rel="reload" as="image" href="{{lists.hero-slider-start.rows[0].background_image_mobile}}">
  <link rel="preload" as="style" href="{{ 'styles.css' | template_path }}?{{ version }}">
  <link rel="preconnect" href="https://fonts.googleapis.com">
  <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>


  <!-- Fonts & Icons -->
  <link
    href="https://fonts.googleapis.com/css2?family=Instrument+Sans:ital,wght@0,100;0,200;0,300;0,400;0,500;0,600;0,700;1,100;1,200;1,300;1,400;1,500;1,600;1,700&family=Barlow:ital,wght@0,100;0,200;0,300;0,400;0,500;0,600;0,700;1,100;1,200;1,300;1,400;1,500;1,600;1,700&display=swap"
    rel="stylesheet">

  <!--- Styles --->
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.7/dist/css/bootstrap.min.css" rel="stylesheet"
        integrity="sha384-LN+7fdVzj6u52u30Kp6M/trliBMCMKTyK833zpbD+pXdCLuTusPj697FH4R/5mcr" crossorigin="anonymous">


  <link href="{{ 'styles.css' | template_path }}?{{ version }}" rel="stylesheet">



  <!---- Scripts --->

  <script src="{{ 'common.js' | template_path }}?{{ version }}" defer></script>
  <script src="{{ 'locale_changer.component.js' | template_path }}?{{ version }}" async></script>


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
    window.recaptcha_public_key = "{{site.recaptcha_public_key}}"
    window.ecomConfig = {
      priceCurrency: "{%if locale == "sv"%}SEK{%else%}EUR{%endif%}",
      priceLocale: "{%if locale == "sv"%}sv-SE{%else%}de-DE{%endif%}",
      priceMinDecimalDigits: 0,
      priceMaxDecimalDigits: 2
    }

  </script>


</head>
<body class="">
<a href="#main-content" class="brand-button-primary w-fit-content" id="skip-link">{{ "Hoppa till huvudinnehåll" | t }}</a>

<header class="main-header">
  {% include 'top_bar' %}
  {% include 'main_menu' %}
</header>

<overlay-component></overlay-component>
<main id="main-content">


