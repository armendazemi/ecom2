<modal-component id="filter-modal" class="side-menu side-menu--left d-flex flex-column " trapfocus="true">
  <div
    class="filter-modal__header d-flex align-items-center justify-content-between padding-x-150 padding-x-lg-300 padding-y-200 border-bottom-1--soft">
    <h2 class="h4">{{ "Filter" | t }}</h2>
    <button type="button" class="icon-button" aria-label="{{ "Stäng filter" | t }}"
            data-modal-action="close"
            data-modal-element="#filter-modal">
      <svg xmlns="http://www.w3.org/2000/svg" width="24" height="25" viewBox="0 0 24 25" fill="none">
        <path
          d="M6.40043 19.1537L5.34668 18.0999L10.9467 12.4999L5.34668 6.89994L6.40043 5.84619L12.0004 11.4462L17.6004 5.84619L18.6542 6.89994L13.0542 12.4999L18.6542 18.0999L17.6004 19.1537L12.0004 13.5537L6.40043 19.1537Z"
          fill="#030712"/>
      </svg>
    </button>
  </div>

  <div class="filter-modal__body">
    <form
      class="d-flex flex-column h-100"
      id="group-filter-form"
      action="{{ request.path }}?"
      method="get">
      <accordion-component class="d-block margin-x-300 border-bottom-1--soft">
        <button type="button"
                class="clear-button fw-regular padding-y-300 justify-content-between w-100 h-auto padding-x-0">
          {{ "Tillgänglighet" | t }}
          <svg class="rotate" xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 20 20"
               fill="none">
            <path
              d="M9.99576 12.5017C9.90645 12.5017 9.8234 12.4857 9.74659 12.4536C9.66978 12.4215 9.5993 12.3735 9.53513 12.3094L5.67201 8.44609C5.55201 8.32609 5.49409 8.19609 5.49826 8.05609C5.50256 7.91623 5.56506 7.78588 5.68576 7.66505C5.80659 7.54436 5.93562 7.48401 6.07284 7.48401C6.21006 7.48401 6.33909 7.54436 6.45992 7.66505L9.99992 11.2261L13.5608 7.66505C13.6762 7.54977 13.8039 7.49422 13.9439 7.49838C14.0837 7.50269 14.2141 7.56519 14.3349 7.68588C14.4556 7.80672 14.516 7.93575 14.516 8.07297C14.516 8.21019 14.4533 8.34116 14.3278 8.46588L10.4647 12.3094C10.395 12.3735 10.3217 12.4215 10.2449 12.4536C10.1681 12.4857 10.0851 12.5017 9.99576 12.5017Z"
              fill="#030712"/>
          </svg>
        </button>
        <div class="dropdown">
          <div class="d-flex flex-column row-gap-100 padding-bottom-300 filter-details__values">
            <label class="d-flex gap-125 text-md mb-0 align-items-center">
              <input
                class="checkbox-default checkbox--brand-primary"
                type="checkbox"
                name="only_in_stock"
                value="true"/>
              <span>{{ "Visa endast produkter som finns i lager" | t }}</span>
            </label>
          </div>
        </div>
      </accordion-component>

      {% for item in lists.filter-groups.rows %}
        {% if item.group[0].id == group.id %}
          {% if item.options == 'true' %}
            {% for type in group.option_types %}
              <accordion-component class="d-block margin-x-300 border-bottom-1--soft">
                <button type="button"
                        class="clear-button fw-regular padding-y-300 justify-content-between w-100 h-auto padding-x-0">
                  {{ type.presentation }}
                  <svg class="rotate" xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 20 20"
                       fill="none">
                    <path
                      d="M9.99576 12.5017C9.90645 12.5017 9.8234 12.4857 9.74659 12.4536C9.66978 12.4215 9.5993 12.3735 9.53513 12.3094L5.67201 8.44609C5.55201 8.32609 5.49409 8.19609 5.49826 8.05609C5.50256 7.91623 5.56506 7.78588 5.68576 7.66505C5.80659 7.54436 5.93562 7.48401 6.07284 7.48401C6.21006 7.48401 6.33909 7.54436 6.45992 7.66505L9.99992 11.2261L13.5608 7.66505C13.6762 7.54977 13.8039 7.49422 13.9439 7.49838C14.0837 7.50269 14.2141 7.56519 14.3349 7.68588C14.4556 7.80672 14.516 7.93575 14.516 8.07297C14.516 8.21019 14.4533 8.34116 14.3278 8.46588L10.4647 12.3094C10.395 12.3735 10.3217 12.4215 10.2449 12.4536C10.1681 12.4857 10.0851 12.5017 9.99576 12.5017Z"
                      fill="#030712"/>
                  </svg>
                </button>
                <div class="dropdown">
                  <div class="d-flex flex-column row-gap-100 padding-bottom-300 filter-details__values">
                    {% for value in type.values %}
                      <label class="d-flex gap-125 text-md mb-0 align-items-center">
                        <input
                          class="checkbox-default checkbox--brand-primary"
                          type="checkbox"
                          name="groups[brands][]"
                          value="{{ value.id }}"/>
                        <span>{{ value.presentation }}</span>
                      </label>
                    {% endfor %}
                  </div>
                </div>
              </accordion-component>
            {% endfor %}
          {% endif %}

          <!-- - end if item.alternativ == 'true' - -->

          {% if item.properties == 'true' %}
            {% assign used_product_properties = group.products.used_product_properties %}
            {% for property in used_product_properties %}
              {% if property.option_category.name contains "Filter" %}
                <accordion-component class="d-block margin-x-300 border-bottom-1--soft">
                  <button type="button"
                          class="clear-button fw-regular padding-y-300 justify-content-between w-100 h-auto padding-x-0">
                    {{ property.presentation }}
                    <svg class="rotate" xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 20 20"
                         fill="none">
                      <path
                        d="M9.99576 12.5017C9.90645 12.5017 9.8234 12.4857 9.74659 12.4536C9.66978 12.4215 9.5993 12.3735 9.53513 12.3094L5.67201 8.44609C5.55201 8.32609 5.49409 8.19609 5.49826 8.05609C5.50256 7.91623 5.56506 7.78588 5.68576 7.66505C5.80659 7.54436 5.93562 7.48401 6.07284 7.48401C6.21006 7.48401 6.33909 7.54436 6.45992 7.66505L9.99992 11.2261L13.5608 7.66505C13.6762 7.54977 13.8039 7.49422 13.9439 7.49838C14.0837 7.50269 14.2141 7.56519 14.3349 7.68588C14.4556 7.80672 14.516 7.93575 14.516 8.07297C14.516 8.21019 14.4533 8.34116 14.3278 8.46588L10.4647 12.3094C10.395 12.3735 10.3217 12.4215 10.2449 12.4536C10.1681 12.4857 10.0851 12.5017 9.99576 12.5017Z"
                        fill="#030712"/>
                    </svg>
                  </button>
                  <div class="dropdown">
                    <div class="d-flex flex-column row-gap-100 filter-details__values padding-bottom-300">
                      {% for value in property.values %}
                        <label class="d-flex gap-125 text-md mb-0 align-items-center">
                          <input
                            class="checkbox-default checkbox--brand-primary"
                            type="checkbox"
                            name="groups[brands][]"
                            value="{{ value.id }}"/>
                          <span>{{ value.presentation }}</span>
                        </label>
                      {% endfor %}
                    </div>
                  </div>
                </accordion-component>
              {% endif %}
            {% endfor %}
          {% endif %}
          <!-- - end if item.egenskaper == 'true' - -->

          {% if item.brands == 'true' %}
            {% assign brands_group = group.groups_with_products_in_common.include_subtree.children_of_brands %}
            {% assign brands_sort = brands_group | sort: "name" %}
            <accordion-component class="d-block margin-x-300 border-bottom-1--soft">
              <button type="button"
                      class="clear-button fw-regular padding-y-300 justify-content-between w-100 h-auto padding-x-0">
                {{ "Varumärken" | t }}
                <svg class="rotate" xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 20 20"
                     fill="none">
                  <path
                    d="M9.99576 12.5017C9.90645 12.5017 9.8234 12.4857 9.74659 12.4536C9.66978 12.4215 9.5993 12.3735 9.53513 12.3094L5.67201 8.44609C5.55201 8.32609 5.49409 8.19609 5.49826 8.05609C5.50256 7.91623 5.56506 7.78588 5.68576 7.66505C5.80659 7.54436 5.93562 7.48401 6.07284 7.48401C6.21006 7.48401 6.33909 7.54436 6.45992 7.66505L9.99992 11.2261L13.5608 7.66505C13.6762 7.54977 13.8039 7.49422 13.9439 7.49838C14.0837 7.50269 14.2141 7.56519 14.3349 7.68588C14.4556 7.80672 14.516 7.93575 14.516 8.07297C14.516 8.21019 14.4533 8.34116 14.3278 8.46588L10.4647 12.3094C10.395 12.3735 10.3217 12.4215 10.2449 12.4536C10.1681 12.4857 10.0851 12.5017 9.99576 12.5017Z"
                    fill="#030712"/>
                </svg>
              </button>
              <div class="dropdown">
                <div class="d-flex flex-column row-gap-100 padding-bottom-300 filter-details__values">
                  {% for brand in brands_sort %}
                    <label class="d-flex gap-125 text-md mb-0 align-items-center">
                      <input
                        class="checkbox-default checkbox--brand-primary"
                        type="checkbox"
                        name="groups[brands][]"
                        value="{{ brand.id }}"/>
                      <span>{{ brand.name }}</span>
                    </label>
                  {% endfor %}
                </div>
              </div>
            </accordion-component>
          {% endif %}

          <accordion-component class="d-block margin-x-300 border-bottom-1--soft">
            <button type="button"
                    class="clear-button fw-regular padding-y-300 justify-content-between w-100 h-auto padding-x-0">
              {{ "Pris" | t }}
              <svg class="rotate" xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 20 20"
                   fill="none">
                <path
                  d="M9.99576 12.5017C9.90645 12.5017 9.8234 12.4857 9.74659 12.4536C9.66978 12.4215 9.5993 12.3735 9.53513 12.3094L5.67201 8.44609C5.55201 8.32609 5.49409 8.19609 5.49826 8.05609C5.50256 7.91623 5.56506 7.78588 5.68576 7.66505C5.80659 7.54436 5.93562 7.48401 6.07284 7.48401C6.21006 7.48401 6.33909 7.54436 6.45992 7.66505L9.99992 11.2261L13.5608 7.66505C13.6762 7.54977 13.8039 7.49422 13.9439 7.49838C14.0837 7.50269 14.2141 7.56519 14.3349 7.68588C14.4556 7.80672 14.516 7.93575 14.516 8.07297C14.516 8.21019 14.4533 8.34116 14.3278 8.46588L10.4647 12.3094C10.395 12.3735 10.3217 12.4215 10.2449 12.4536C10.1681 12.4857 10.0851 12.5017 9.99576 12.5017Z"
                  fill="#030712"/>
              </svg>
            </button>
            <div class="dropdown">
              <range-slider id="" class="d-flex flex-column row-gap-300 padding-y-300" min="0"
                            max="{{ filter_max_price }}"></range-slider>
            </div>
          </accordion-component>

        {% endif %}
      {% endfor %}
    </form>
  </div>

  <div class="side-cart__footer mt-auto d-flex flex-column flex-lg-row gap-125 padding-300">
    <button
      type="button"
      id="clearFormBtn"
      class="brand-button-secondary button-large text-primary fw-semi flex-grow-1">
      {{ "Rensa filter" | t }}
    </button>

    <button
      type="submit"
      form="group-filter-form"
      class="brand-button-primary button-large text-white flex-grow-1">
      {{ "Visa produkter" | t }}
    </button>
  </div>
</modal-component>

{% include 'groups_structured_data' %}


<script>
  // ----------------------------------------------
  //  Filter handling
  //  ----------------------------------------------

  // Get all url parameters
  const urlParams = new URLSearchParams(window.location.search);

  // Find radio and checkboxes and set them to checked if they are in the url
  // There can be multiple values for the same key in the url
  const radios = document.querySelectorAll('input[type="radio"]');
  const checkboxes = document.querySelectorAll('input[type="checkbox"]');
  const checkedItems = [];
  radios.forEach(radio => {
    if (urlParams.has(radio.name)) {
      if (urlParams.get(radio.name) === radio.value) {
        radio.checked = true;
        checkedItems.push(radio);
      }
    }
  });

  checkboxes.forEach(checkbox => {
    if (urlParams.has(checkbox.name)) {
      if (urlParams.getAll(checkbox.name).includes(checkbox.value)) {
        checkbox.checked = true;
        checkedItems.push(checkbox);
      }
    }
  });

  // Add filters to filter-active-options div from checked checkboxes and radios
  // Get the label text of the checked checkboxes and radios and add them to the active filters div
  const activeFilters = document.querySelector('.active-group-filters');

  if (checkedItems.length > 0) {
    checkedItems.forEach(input => {
      let filterName = input.name.replace(/^(?:filter|groups)\[([^\]]+)\](?:\[\])?$/g, '$1').replace(/^./, match => match.toUpperCase());

      filterName = filterName === 'Varumarken' ? 'Varumärken' : filterName;
      const label = input.parentElement.querySelector('span').textContent;
      const value = input.value;

      const filter = document.createElement('button');
      filter.classList.add('filter-chip', 'clear-filter-button');
      filter.dataset.value = value;

      if (filterName === 'Sort') {
        let filterName = window.getTranslation('Sortera');
        filter.textContent = filterName + ': ' + label;
        filter.dataset.type = 'Sort';
      } else if (filterName === 'Only_in_stock') {
        filter.textContent = window.getTranslation('Endast i lager');
        filter.dataset.type = 'only_in_stock';
      } else {
        filter.textContent = filterName + ': ' + label;
        filter.dataset.type = input.name;
      }

      filter.innerHTML +=
        `<svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 20 20" fill="none">
        <path d="M6.06253 14.7115L5.28857 13.9375L9.22607 10L5.28857 6.06253L6.06253 5.28857L10 9.22607L13.9375 5.28857L14.7115 6.06253L10.774 10L14.7115 13.9375L13.9375 14.7115L10 10.774L6.06253 14.7115Z" fill="#030712"/>
      </svg>`;
      activeFilters.insertBefore(filter, activeFilters.firstChild);
    });
    activeFilters.style.display = 'flex';
  } else {
    activeFilters.style.display = 'none';
  }

  const rangeSlider = document.querySelector('#filter-modal range-slider');
  // If there is a price range in the url, set the range slider to that range
  if (urlParams.has('Price[min]') && urlParams.has('Price[max]')) {
    rangeSlider.setAttribute('start', urlParams.get('Price[min]'));
    rangeSlider.setAttribute('end', urlParams.get('Price[max]'));
  }

  // Add the price range to active filters, if the values are not the default values
  if (rangeSlider &&
    rangeSlider.hasAttribute('start') && rangeSlider.hasAttribute('end') &&
    (rangeSlider.getAttribute('end') !== rangeSlider.getAttribute('max') ||
      rangeSlider.getAttribute('start') !== rangeSlider.getAttribute('min'))) {
    const priceFilter = document.createElement('button');
    priceFilter.dataset.type = 'Price';

    priceFilter.classList.add('filter-chip', 'clear-filter-button');
    priceFilter.textContent = `${window.getTranslation('Pris')}: ${rangeSlider.getAttribute('start')}${window.currencySymbol} - ${rangeSlider.getAttribute('end')}${window.currencySymbol}`;

    priceFilter.innerHTML +=
      `<svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 20 20" fill="none">
        <path d="M6.06253 14.7115L5.28857 13.9375L9.22607 10L5.28857 6.06253L6.06253 5.28857L10 9.22607L13.9375 5.28857L14.7115 6.06253L10.774 10L14.7115 13.9375L13.9375 14.7115L10 10.774L6.06253 14.7115Z" fill="#030712"/>
      </svg>`;
    activeFilters.insertBefore(priceFilter, activeFilters.firstChild);

    activeFilters.style.display = 'flex';
  }

  // Clear the form
  document.getElementById('clearFormBtn').addEventListener('click', () => {
    // Remove all the params and just plain url
    window.location.href = window.location.pathname;
  });

  // Clear filter button handling
  window.addEventListener('click', handleFilterClear);
  window.addEventListener('keydown', handleFilterClear);

  function handleFilterClear (e) {
    const isClick = e.type === 'click';
    const isKeyboard =
      e.type === 'keydown' && (e.key === 'Enter' || e.key === ' ');

    if (!isClick && !isKeyboard) return;

    const target = e.target.closest('.clear-filter-button');
    if (!target) return;

    // Prevent page scroll on space
    if (isKeyboard) e.preventDefault();

    const type = target.dataset.type;
    const value = target.dataset.value || 0;
    const urlParams = new URLSearchParams(window.location.search);

    if (type === 'Price') {
      // Remove both price parameters
      urlParams.delete('Price[min]');
      urlParams.delete('Price[max]');
    } else {
      const values = urlParams.getAll(type);
      const newValues = values.filter(val => val !== value);
      urlParams.delete(type);
      newValues.forEach(val => urlParams.append(type, val));
    }

    window.location.search = urlParams.toString();
  }

  // Update filter count in filter button
  const filterButton = document.querySelector('button[data-modal-element="#filter-modal"]');
  const filterCountSpan = filterButton.querySelector('.filter-count');
  const activeFilterButtons = document.querySelectorAll('.active-group-filters .filter-chip');
  filterCountSpan.textContent = `(${activeFilterButtons.length})`;
</script>