<modal-component id="newsletter-modal" class="default-modal bg-white">
  <div class="default-modal__header ">
    <h2 class="display-xs ">{{ "Nyhetsbrev titel" | t }}</h2>
    <button type="button" class="icon-button btn-close " data-modal-action="close"
            data-modal-element="#newsletter-modal" aria-label="{{ "Stäng modalen för nyhetsbrev" | t }}"></button>
  </div>
  <div class="default-modal__content">
    <p class="text-secondary">{{ "Nyhetsbrev brödtext" | t }}</p>
  </div>
  <div class="default-modal__footer">
    <button type="button" class="brand-button-primary" data-modal-action="close"
            data-modal-element="#newsletter-modal">{{ "Stäng" | t }}</button>
  </div>
</modal-component>