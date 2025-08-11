<nav class="top-bar bg-brand-primary padding-y-150 d-none d-lg-block">
  <div class="container">
    <div class="row align-items-center justify-content-end column-gap-150">
      <div class="col-auto d-flex align-items-center column-gap-150">
        {{ 'top-bar-links' | global_editable: class: 'd-flex align-items-center column-gap-150 text-white text-sm' }}
        <a href="/{{ locale }}/community" class="text-sm text-white">
          {{ "Logga in" | t }}
          <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 20 20" fill="none">
            <path
              d="M9.99204 16.5833V15.5H15.2435C15.3077 15.5 15.3664 15.4732 15.4198 15.4198C15.4732 15.3664 15.5 15.3077 15.5 15.2435V4.75642C15.5 4.69225 15.4732 4.6335 15.4198 4.58017C15.3664 4.52669 15.3077 4.49996 15.2435 4.49996H9.99204V3.41663H15.2435C15.6186 3.41663 15.9357 3.54614 16.1948 3.80517C16.4538 4.0642 16.5833 4.38128 16.5833 4.75642V15.2435C16.5833 15.6186 16.4538 15.9357 16.1948 16.1948C15.9357 16.4538 15.6186 16.5833 15.2435 16.5833H9.99204ZM9.02892 12.891L8.24683 12.1329L9.83808 10.5416H3.41663V9.45829H9.83808L8.24683 7.86704L9.02892 7.10892L11.9198 9.99996L9.02892 12.891Z"
              fill="white"/>
          </svg>
        </a>
      </div>
    </div>
  </div>
</nav>
