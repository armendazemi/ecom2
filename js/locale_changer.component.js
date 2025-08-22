class LocaleChanger extends HTMLElement {
  constructor () {
    super();
  }

  connectedCallback () {
    this._setupLocaleListeners();
  }

  disconnectedCallback () {
    const localeLinks = this.querySelectorAll('[data-locale]');
    localeLinks.forEach(link => {
      link.removeEventListener('click', this._handleLocaleChange);
    });
  }

  _setupLocaleListeners () {
    const localeLinks = this.querySelectorAll('[data-locale]');

    localeLinks.forEach(link => {
      link.addEventListener('click', this._handleLocaleChange.bind(this));
    });
  }

  _handleLocaleChange (event) {
    event.preventDefault();
    const target= event.target;
    const currentUrl = window.location.href;
    const newLocale = target.getAttribute('data-locale');
    window.location.href = this._getUrlForLocaleURLApi(currentUrl, newLocale);
  }

  /**
   * Generates a new URL with the specified locale, and replaces the existing locale in the URL path if present.
   * @param currentUrl - the current URL to modify
   * @param newLocale - the new locale to set in the URL
   * @returns {*|string} - the modified URL with the new locale
   * @private
   */
  _getUrlForLocaleURLApi (currentUrl, newLocale) {
    try {
      const url = new URL(currentUrl);
      const pathSegments = url.pathname.split('/').filter(segment => segment !== '');

      let existingLocale = null;
      if (pathSegments.length > 0 && /^[a-z]{2}$/i.test(pathSegments[0])) {
        existingLocale = pathSegments[0].toLowerCase();
      }

      let newPathSegments = [...pathSegments];

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
}

customElements.define('locale-changer', LocaleChanger);