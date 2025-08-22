<!DOCTYPE html>
<html lang="{{ locale }}">
<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge"/>
  <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">

  <title>{{ title | t | fallback: seo.title }}</title>
  <meta name="description" content="{{ seo.description }}">
  <meta name="keywords" content="{{ seo.keywords }}">

  <meta property="og:title" content="{{ page.title }}"/>
  <meta property="og:description" content="{{ page.og_description }}"/>
  <meta property="og:image" content="{{ page.og_image }}"/>

  {% if locale == "sv" %}
    <link href="https://ecom2.se/{{ request.path }}" rel="canonical">
  {% elsif locale == "en" %}
    <link href="https://ecom2.se/en/{{ request.path }}" rel="canonical">
  {% endif %}
  <link rel="alternate" hreflang="sv" href="https://ecom2.se/"/>
  <link rel="alternate" hreflang="en" href="https://ecom2.se/en"/>

  <link rel="icon" href="{{ 'favicon.png' | asset_path }}">


  {{ wm3 }}
  {{ wm3_public_ecom_javascript }}

  <link rel="alternate" type="application/rss+xml" href="/{{ locale }}/a.rss" title="RSS Feed">

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

  <!--- Preload the first hero mobile image to improve mobile performance --->


  <!---- Scripts --->

  <script src="{{ 'common.js' | template_path }}?{{ version }}" defer></script>
  <script src="{{ 'locale_changer.component.js' | template_path }}?{{ version }}" async></script>


</head>
<body class="">
<a href="#main-content" class="brand-button-primary w-fit-content" id="skip-link">{{ "Hoppa till huvudinnehåll" | t }}</a>

<header class="main-header">
  {% include 'top_bar' %}
  {% include 'main_menu' %}
</header>

<overlay-component></overlay-component>
<main id="main-content">


