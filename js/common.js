document.addEventListener('DOMContentLoaded', function () {
  setupLocaleListeners();
  setupMenuDropdowns();

});

function setupLocaleListeners () {
  const localeLinks = document.querySelectorAll('[data-locale-link]');
  const currentUrl = window.location.href;

  localeLinks.forEach(link => {
    link.addEventListener('click', (event) => {
      event.preventDefault();
      const newLocale = link.getAttribute('data-locale-link');
      window.location.href = getUrlForLocaleURLApi(currentUrl, newLocale);
    });
  });
}

function getUrlForLocaleURLApi (currentUrl, newLocale) {
  try {
    const url = new URL(currentUrl);
    const pathSegments = url.pathname.split('/').filter(segment => segment !== '');

    let existingLocale = null;
    if (pathSegments.length > 0 && /^[a-z]{2}$/i.test(pathSegments[0])) {
      existingLocale = pathSegments[0].toLowerCase();
    }

    let newPathSegments = [...pathSegments];

// Remove the existing locale segment if it was found
    if (existingLocale) {
      newPathSegments.shift();
    }

    newPathSegments.unshift(newLocale.toLowerCase());

    url.pathname = '/' + newPathSegments.join('/');

    return url.toString();

  } catch (e) {
    console.error('Error processing URL with URL API:', e);
    return currentUrl;
  }
}

function setupMenuDropdowns () {
  const navItems = document.querySelectorAll('.nav-item-wrapper');

  navItems.forEach(item => {
    const dropdown = item.querySelector('.nav-item__dropdown');

    if (!dropdown) return;

    // Open on mouse enter
    item.addEventListener('mouseenter', () => openDropdown(item));

    // Close on mouse leave
    item.addEventListener('mouseleave', () => closeDropdown(item));

    // Open on focus-in (keyboard navigation)
    item.addEventListener('focusin', () => openDropdown(item));

    // Close on focus-out (when tabbing away)
    item.addEventListener('focusout', (e) => {
      // Close only if focus moves outside the item
      if (!item.contains(e.relatedTarget)) {
        closeDropdown(item);
      }
    });
  });

  function openDropdown (item) {
    const dropdown = item.querySelector('.nav-item__dropdown');
    item.classList.add('open');
    item.setAttribute('aria-expanded', 'true');
    dropdown.style.display = 'block';
  }

  function closeDropdown (item) {
    const dropdown = item.querySelector('.nav-item__dropdown');
    item.classList.remove('open');
    item.setAttribute('aria-expanded', 'false');
    dropdown.style.display = 'none';
  }



  // -------------------------------------
  // Aria-expanded handling
  // --------------------------------------

  function handleAriaExpanded (e) {
    const element = e.target;
    const currentState = element.getAttribute('aria-expanded') === 'true';
    element.setAttribute('aria-expanded', String(!currentState));
  }

  document.addEventListener('click', (e) => {
    const element = e.target;
    if (element.hasAttribute('aria-expanded')) {
      handleAriaExpanded(e);
    }
  });

  // Handle aria-expanded for modal buttons
  window.addEventListener('modalchange', (e) => {
    const modalElement = e.detail.element;
    const modalButton = document.querySelector(`[data-modal-element='${modalElement}']`);
    if (!modalButton) return;

    const action = e.detail.action;
    if (action === 'close') {
      modalButton.setAttribute('aria-expanded', 'false');
    } else {
      modalButton.setAttribute('aria-expanded', 'true');
    }

  });
}