{% wm3form customer.update_url, id = "customer-update-form", class = "d-flex flex-column row-gap-300 needs-validation" %}

{% if flash.notice %}
  <div class="alert alert-success">{{ flash.notice | join: '</div><div class="notice">' }}</div>
{% endif %}
{% if flash.alert %}
  <div class="alert alert-danger">{{ flash.alert | join: '</div><div class="alert default-message">' }}</div>
{% endif %}
{% if customer.notifications.exists? %}
  {% for alert in customer.notifications.by_type.alert %}
    <div class="alert alert-warning spacer-10">{{ alert.message }}</div>
  {% endfor %}
{% endif %}

{% unless customer.see_taxes_in_webshop %}

  <fieldset class="d-flex flex-column row-gap-300">
    <legend>{{ "Kunduppgifter" | t }}</legend>

    <div class="row">
      <div class="col-lg input-group has-validation d-flex flex-column">
        <label for="firstName">{{ "Förnamn" | t }}</label>
        <input value="{{ customer.first_name }}" type="text" class="form-control input-default w-100" id="firstName"
               name="customer[first_name]"
               placeholder="{{ 'Förnamn' | t }}" aria-label="{{ 'Förnamn' | t }}" required>
        <div class="invalid-feedback">
          {{ "Ange ditt förnamn" | t }}
        </div>
      </div>
      <div class="col-lg input-group has-validation d-flex flex-column">
        <label for="lastName">{{ "Efternamn" | t }}</label>
        <input value="{{ customer.last_name }}" type="text" class="form-control input-default w-100" id="lastName"
               name="customer[last_name]"
               placeholder="{{ 'Efternamn' | t }}" aria-label="{{ 'Efternamn' | t }}" required>
        <div class="invalid-feedback">
          {{ "Ange ditt efternamn" | t }}
        </div>
      </div>
    </div>

    <div class="input-group has-validation d-flex flex-column">
      <label for="company">{{ "Företag" | t }}</label>
      <input value="{{ customer.company }}" type="text" class="form-control input-default w-100" id="company"
             name="customer[company]"
             placeholder="{{ 'Företag' | t }}" aria-label="{{ 'Företag' | t }}" required>
      <div class="invalid-feedback">
        {{ "Ange ditt företagsnamn" | t }}
      </div>
    </div>

    <div class="input-group has-validation d-flex flex-column">
      <label for="email">{{ "Email" | t }}</label>
      <input value="{{ customer.email }}" type="email" class="form-control w-100 input-default" id="email"
             name="customer[email]" required>
      <div class="invalid-feedback">
        {{ "Ange en giltig e-postadress" | t }}
      </div>
    </div>
  </fieldset>

  <fieldset class="row">
    <legend>{{ "Faktureringsuppgifter" | t }}</legend>

    <div class="col-12 mt-3">
      <div class="input-group has-validation d-flex flex-column">
        <label for="fakt_bill_company">{{ 'Företagsnamn' | t }}</label>
        <input class="input-default form-control w-100" name="customer[bill_address_attributes][company]"
               type="text" value="{{ customer.bill_address.company }}" id="fakt_bill_company">
      </div>
    </div>

    <div class="col-12 mt-3">
      <div class="input-group has-validation d-flex flex-column">
        <label for="fakt_bill_address1">{{ 'Faktureringsadress' | t }}</label>
        <input class="input-default form-control w-100" name="customer[bill_address_attributes][address1]"
               type="text" value="{{ customer.bill_address.address1 }}" id="fakt_bill_address1">
      </div>
    </div>

    <div class="col-12 col-lg-6 mt-3">
      <div class="input-group has-validation d-flex flex-column">
        <label for="fakt_bill_zipcode">{{ 'Postnummer' | t }}</label>
        <input class="input-default form-control w-100" name="customer[bill_address_attributes][zipcode]"
               type="text" value="{{ customer.bill_address.zipcode }}" id="fakt_bill_zipcode">
      </div>
    </div>

    <div class="col-12 col-lg-6 mt-3">
      <div class="input-group has-validation d-flex flex-column">
        <label for="fakt_bill_city">{{ 'Postort' | t }}</label>
        <input class="input-default form-control w-100" name="customer[bill_address_attributes][city]"
               type="text" value="{{ customer.bill_address.city }}" id="fakt_bill_city">
      </div>
    </div>

    <div class="col-12 mt-3">
      <div class="input-group has-validation d-flex flex-column">
        <label for="fakt_bill_country">{{ 'Land' | t }}</label>
        <select class="w-100 radius-full" name="customer[bill_address_attributes][country_id]" id="fakt_bill_country">
          {% for country in store.countries %}
            <option value="{{ country.id }}"
                    {% if customer.bill_address.country_id == country.id %}selected{% endif %}>{{ country.name }}</option>
          {% endfor %}
        </select>
      </div>
    </div>
  </fieldset>

  <fieldset class="row">
    <legend>{{ "Leveransuppgifter" | t }}</legend>

    <div class="col-12 mt-3">
      <div class="input-group has-validation d-flex flex-column">
        <label for="lev_bill_company">{{ 'Företagsnamn' | t }} *</label>
        <input class="input-default form-control w-100" name="customer[bill_address_attributes][company]"
               type="text" value="{{ customer.bill_address.company }}" id="lev_bill_company" required>
      </div>
    </div>

    <div class="col-12 mt-3">
      <div class="input-group has-validation d-flex flex-column">
        <label for="lev_bill_address1">{{ 'Leveransadress' | t }} *</label>
        <input class="input-default form-control w-100" name="customer[bill_address_attributes][address1]"
               type="text" value="{{ customer.bill_address.address1 }}" id="lev_bill_address1" required>
      </div>
    </div>

    <div class="col-12 col-lg-6 mt-3">
      <div class="input-group has-validation d-flex flex-column">
        <label for="lev_bill_zipcode">{{ 'Postnummer' | t }} *</label>
        <input class="input-default form-control w-100" name="customer[bill_address_attributes][zipcode]"
               type="text" value="{{ customer.bill_address.zipcode }}" id="lev_bill_zipcode" required>
      </div>
    </div>

    <div class="col-12 col-lg-6 mt-3">
      <div class="input-group has-validation d-flex flex-column">
        <label for="lev_bill_city">{{ 'Postort' | t }} *</label>
        <input class="input-default form-control w-100" name="customer[bill_address_attributes][city]"
               type="text" value="{{ customer.bill_address.city }}" id="lev_bill_city" required>
      </div>
    </div>

    <div class="col-12 mt-3">
      <div class="input-group has-validation d-flex flex-column">
        <label for="lev_bill_country">{{ 'Land' | t }} *</label>
        <select class="w-100 radius-full" name="customer[bill_address_attributes][country_id]" id="lev_bill_country"
                required>
          {% for country in store.countries %}
            <option value="{{ country.id }}"
                    {% if customer.bill_address.country_id == country.id %}selected{% endif %}>{{ country.name }}</option>
          {% endfor %}
        </select>
      </div>
    </div>
  </fieldset>

  <fieldset class="row">
    <legend>{{ "Övriga uppgifter" | t }}</legend>

    <div class="col-12 mt-3">
      <div class="input-group has-validation d-flex flex-column">
        <label for="bill_email">{{ 'Email – för faktura' | t }}</label>
        <input class="input-default form-control w-100" name="customer[dynamic_fields][faktura-email][value]"
               type="email" value="{{ customer.dynamic_fields.faktura-email.value }}" id="bill_email">
      </div>
    </div>

    <div class="col-12 mt-3">
      <div class="input-group has-validation d-flex flex-column">
        <label for="gln-number">{{ 'GLN-nummer' | t }}</label>
        <input class="input-default form-control w-100" name="customer[dynamic_fields][gln-nummer][value]"
               type="text" value="{{ customer.dynamic_fields.gln-nummer.value }}" id="gln-number">
      </div>
    </div>

    <div class="col-12 mt-3">
      <div class="input-group has-validation d-flex flex-column">
        <label for="organisationsnummer">{{ 'Organisationsnummer' | t }}</label>
        <input class="input-default form-control w-100" name="customer[dynamic_fields][organisationsnummer][value]"
               type="text" value="{{ customer.dynamic_fields.organisationsnummer.value }}" id="organisationsnummer">
      </div>
    </div>
  </fieldset>

{% else %}

  <div class="row">
    <div class="col-lg input-group has-validation d-flex flex-column">
      <label for="firstName">{{ "Förnamn" | t }}</label>
      <input value="{{ customer.first_name }}" type="text" class="form-control input-default w-100" id="firstName"
             name="customer[first_name]"
             placeholder="{{ 'Förnamn' | t }}" aria-label="{{ 'Förnamn' | t }}" required>
      <div class="invalid-feedback">
        {{ "Ange ditt förnamn" | t }}
      </div>
    </div>
    <div class="col-lg input-group has-validation d-flex flex-column">
      <label for="lastName">{{ "Efternamn" | t }}</label>
      <input value="{{ customer.last_name }}" type="text" class="form-control input-default w-100" id="lastName"
             name="customer[last_name]"
             placeholder="{{ 'Efternamn' | t }}" aria-label="{{ 'Efternamn' | t }}" required>
      <div class="invalid-feedback">
        {{ "Ange ditt efternamn" | t }}
      </div>
    </div>
  </div>

  <div class="input-group has-validation d-flex flex-column">
    <label for="email">{{ "Email" | t }}</label>
    <input value="{{ customer.email }}" type="email" class="form-control w-100 input-default" id="email"
           name="customer[email]" required>
    <div class="invalid-feedback">
      {{ "Ange en giltig e-postadress" | t }}
    </div>
  </div>

  <div class="input-group d-flex flex-column">
    <label for="phone">{{ "Mobilnummer" | t }}</label>
    <input type="tel" class="form-control w-100 input-default" id="phone" name="customer[phone]">
  </div>

{% endunless %}

<button type="submit" class="brand-button-primary w-fit-content">{{ "Spara ändringarna" | t }}</button>
{% endwm3form %}


{% wm3form customer.update_url, id = "customer-update-form", class = "d-flex flex-column row-gap-300 needs-validation margin-top-100 margim-top-lg-300" %}

<div class="input-group has-validation d-flex flex-column">
  <label for="passwordCurrent">{{ "Lösenord" | t }}</label>
  <input type="password" class="form-control w-100 input-default" id="passwordCurrent" name="customer[current_password]"
         required>
  <div class="invalid-feedback">
    {{ "Ange ditt nuvarnde lösenord" | t }}
  </div>
</div>

<div class="input-group has-validation d-flex flex-column">
  <label for="password">{{ "Lösenord" | t }}</label>
  <input type="password" class="form-control w-100 input-default" id="password" name="customer[password]"
         minlength="6"
         required>
  <span class="text-tiny">{{ "Lösenordet måste vara minst 6 tecken" | t }}</span>
  <div class="invalid-feedback">
    {{ "Ange ditt lösenord" | t }}
  </div>
</div>

<div class="input-group has-validation d-flex flex-column">
  <label for="passwordConfirm">{{ "Bekräfta ditt lösenord" | t }}</label>
  <input type="password" class="form-control input-default w-100" id="passwordConfirm" minlength="6"
         name="customer[password_confirmation]" required>
  <div class="invalid-feedback">
    {{ "Bekräfta ditt lösenord" | t }}
  </div>
</div>


<div class="d-flex align-items-center column-gap-75">
  <input type="checkbox" name="show_password" id="show_password">
  <label class="mb-0 text-md fw-regular" for="show_password">
    {{ "Visa lösenord" | t }}
  </label>
</div>

<button type="submit" class="brand-button-primary w-fit-content">{{ "Spara ändringarna" | t }}</button>
{% endwm3form %}


<script>
  document.addEventListener('DOMContentLoaded', () => {
    const showPasswordCheckbox = document.getElementById('show_password');
    const passwordInputs = ['passwordCurrent', 'password', 'passwordConfirm'].map(id => document.getElementById(id));

    showPasswordCheckbox.addEventListener('change', (event) => {
      if (event.target.checked) {
        passwordInputs.forEach(input => input.type = 'text');
      } else {
        passwordInputs.forEach(input => input.type = 'password');
      }
    });
  });
</script>