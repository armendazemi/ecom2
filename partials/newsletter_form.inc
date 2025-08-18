{{ 'newsletter-title' | global_editable: class: 'display-subheading-heading d-flex flex-column row-gap-200 p-color-secondary' }}
<form-component action="/n/subscribe" method="post" modal="#newsletter-modal"
                class="newsletter-signup d-flex align-items-center gap-150 flex-wrap">
  <div class="input-group has-validation column-gap-150">
    <input type="email" class="input-default col form-control"
           aria-label="{{ "Gå med i vårt nyhetsbrev" | t }}"
           placeholder="{{ "Din e-postadress" | t }}" name="subscriber[email]" autocomplete="off" required>
    <input type="hidden" name="group" value="web">
    <button type="submit" class="brand-button-primary ">{{ "Prenumerera" }}</button>
    <div class="invalid-feedback">
      {{ "Du måste fyll i en giltig e-postadress" | t }}
    </div>
  </div>
  <div class="w-100">
    {{ 'newsletter-conset-text' | global_editable: class: 'text-tiny p-color-secondary' }}
  </div>
</form-component>