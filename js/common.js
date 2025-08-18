const toggleVisibility = window.ecomUtils.toggleVisibility;
const CLOSE_TIMEOUT = 150;

document.addEventListener('DOMContentLoaded', function () {
  setupLocaleListeners();
  setupMenuDropdowns();
  setupHoverModals();
  setupImageFlip();
});

// -------------------------------------
// Locale handling
// --------------------------------------

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

// -------------------------------------
// Menu dropdown handling
// --------------------------------------

function setupMenuDropdowns () {
  const navItems = document.querySelectorAll('.nav-item-wrapper');

  navItems.forEach(item => {
    const parent = item.parentElement;
    const dropdown = parent.querySelector('.nav-item__dropdown');
    let closeTimer;

    if (!dropdown) return;
    item.addEventListener('mouseenter', () => {
      handleDropdownAction(item);
      clearTimeout(closeTimer);
    });

    // Follow link on click
    item.addEventListener('click', (e) => {
      e.preventDefault();
      window.location.href = item.getAttribute('data-follow-link') || '#';
    });

    // Open and follow link if dropdown is open
    item.addEventListener('keydown', (e) => {
      if (e.key === 'Escape') {
        closeDropdown(item, dropdown);
      }
      if (e.key === 'Enter' || e.key === ' ') {
        e.preventDefault();
        if (dropdown.classList.contains('open')) {
          window.location.href = item.getAttribute('data-follow-link') || '#';
        } else {
          handleDropdownAction(item);
        }
      }
    });

    parent.addEventListener('focusout', (e) => {
      setTimeout(() => {
        if (!parent.contains(document.activeElement)) {
          closeDropdown(item, dropdown);
        }
      }, 0);
    });

    parent.addEventListener('mouseleave', () => {
      closeTimer = setTimeout(() => {
        closeDropdown(item, dropdown);
      }, CLOSE_TIMEOUT);
    });

    parent.addEventListener('mouseenter', () => {
      clearTimeout(closeTimer);
    });

  });
}

function handleDropdownAction (item) {
  const dropdown = item.parentElement.querySelector('.nav-item__dropdown');
  if (dropdown.classList.contains('open')) {
    closeDropdown(item, dropdown);
  } else {
    openDropdown(item, dropdown);
  }
}

function openDropdown (item, dropdown) {
  window.dispatchEvent(new Event('modalcloseall'));
  item.setAttribute('aria-expanded', 'true');
  toggleVisibility(dropdown, 'open');
}

function closeDropdown (item, dropdown) {
  item.setAttribute('aria-expanded', 'false');
  toggleVisibility(dropdown, 'close');
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

// -------------------------------------
// Modal handling
// --------------------------------------
function setupHoverModals () {
  const modalHoverTriggers = document.querySelectorAll('[data-modal-hover-open]');

  modalHoverTriggers.forEach(trigger => {
    const modalSelector = trigger.getAttribute('data-modal-element');
    const modalElement = document.querySelector(modalSelector);
    let closeTimer;

    const openModal = (e) => {
      clearTimeout(closeTimer);
      if (!modalElement.classList.contains('open')) {
        trigger.click();
      }
    };

    const startCloseTimer = () => {
      clearTimeout(closeTimer);
      closeTimer = setTimeout(() => {
        window.dispatchEvent(new CustomEvent('modalchange', {
          detail: {
            action: 'close',
            initiator: trigger,
            element: modalSelector
          }
        }));
      }, CLOSE_TIMEOUT);
    };

    const cancelCloseTimer = () => {
      clearTimeout(closeTimer);
    };

    trigger.addEventListener('mouseenter', openModal);
    trigger.addEventListener('mouseleave', startCloseTimer);
    trigger.addEventListener('click', (e) => {

      if (modalElement.classList.contains('open')) {
        e.preventDefault();
        window.location.href = trigger.getAttribute('data-follow-link') || '#';
      }
    });

    if (modalElement) {
      modalElement.addEventListener('mouseenter', cancelCloseTimer);
      modalElement.addEventListener('mouseleave', startCloseTimer);
    }
  });
}

function setupImageFlip () {
  const productFlipCards = document.querySelectorAll('.product-card-flip');
  if (!productFlipCards) return;

  const productFlipCardsWithValues = Array.from(productFlipCards).filter((card) => {
    const image = card.querySelector('.image-flip');
    const backsideValue = image.getAttribute('data-backside-image');
    return backsideValue && backsideValue.trim() !== '';
  });

  if (productFlipCardsWithValues.length === 0) return;
  productFlipCardsWithValues.forEach(handleImageFlip);
}

function handleImageFlip (flipCard) {

  flipCard.addEventListener('mouseenter', () => {
    const image = flipCard.querySelector('.image-flip');
    const backsideValue = image.getAttribute('data-backside-image');
    console.log('Fetching new image for:', flipCard);
    image.src = backsideValue;
  });
}