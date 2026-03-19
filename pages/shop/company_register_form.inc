<form-component action="{{ customer.register_url }}" method="post" id="login-page-form"
                redirect="{{ customer.login_url }}" no-clear
                class="d-flex flex-column row-gap-200 needs-validation" novalidate>

  <fieldset>
    <legend>{{ "Kunduppgifter" | t }}</legend>
    <div class="row">
      <div class="col-lg input-group mt-3 has-validation d-flex flex-column">
        <label for="firstName">{{ "Förnamn" | t }}</label>
        <input type="text" class="form-control input-default w-100" id="firstName" name="customer[first_name]"
               placeholder="{{ 'Förnamn' | t }}" aria-label="{{ 'Förnamn' | t }}" required>
        <div class="invalid-feedback">
          {{ "Ange ditt förnamn" | t }}
        </div>
      </div>
      <div class="col-lg input-group mt-3 has-validation d-flex flex-column">
        <label for="lastName">{{ "Efternamn" | t }}</label>
        <input type="text" class="form-control input-default w-100" id="lastName" name="customer[last_name]"
               placeholder="{{ 'Efternamn' | t }}" aria-label="{{ 'Efternamn' | t }}" required>
        <div class="invalid-feedback">
          {{ "Ange ditt efternamn" | t }}
        </div>
      </div>
    </div>

    <div class="col-lg input-group mt-3 has-validation d-flex flex-column">
      <label for="company">{{ "Företag" | t }}</label>
      <input type="text" class="form-control input-default w-100" id="company" name="customer[company]"
             placeholder="{{ 'Företag' | t }}" aria-label="{{ 'Företag' | t }}" required>
      <div class="invalid-feedback">
        {{ "Ange ditt företagsnamn" | t }}
      </div>
    </div>

    <div class="input-group mt-3 has-validation d-flex flex-column">
      <label for="email">{{ "Email" | t }}</label>
      <input type="email" class="form-control w-100 input-default" id="email" name="customer[email]" required>
      <div class="invalid-feedback">
        {{ "Ange en giltig e-postadress" | t }}
      </div>
    </div>


    <div class="input-group mt-3 has-validation d-flex flex-column">
      <label for="password-company">{{ "Lösenord" | t }}</label>
      <input type="password" class="form-control w-100 input-default" id="password-company" name="customer[password]"
             minlength="6"
             required>
      <span class="text-tiny">{{ "Lösenordet måste vara minst 6 tecken" | t }}</span>
      <div class="invalid-feedback">
        {{ "Ange ditt lösenord" | t }}
      </div>
    </div>

    <div class="input-group mt-3 has-validation d-flex flex-column">
      <label for="passwordConfirm-company">{{ "Bekräfta ditt lösenord" | t }}</label>
      <input type="password" class="form-control input-default w-100" id="passwordConfirm-company" minlength="6"
             name="customer[password_confirmation]" required>
      <div class="invalid-feedback">
        {{ "Bekräfta ditt lösenord" | t }}
      </div>
    </div>

    <div class="d-flex align-items-center column-gap-75 mt-3">
      <input type="checkbox" name="show_password" id="show_password" class="password-reveal">
      <label class="mb-0 text-md fw-regular" for="show_password">
        {{ "Visa lösenord" | t }}
      </label>
    </div>
  </fieldset>

  <fieldset class="row">
    <legend>{{ "Faktureringsuppgifter " | t }}</legend>
    <div class="col-12 mt-3">
      <div class="input-group has-validation">
        <label for="bill_company">{{ 'Företagsnamn' | t }}</label>
        <input class="input-default form-control w-100" name="customer[bill_address_attributes][company]"
               type="text"
               value="{{ customer.bill_address.company }}" id="bill_company">
      </div>
    </div>

    <div class="col-12 mt-3">
      <div class="input-group has-validation">
        <label for="bill_address1">{{ 'Faktureringsadress' | t }}</label>
        <input class="input-default form-control w-100" name="customer[bill_address_attributes][address1]"
               type="text"
               value="{{ customer.bill_address.address1 }}" id="bill_address1">
      </div>
    </div>

    <div class="col-12 col-lg-6 mt-3">
      <div class="input-group has-validation">
        <label for="bill_zipcode">{{ 'Postnummer' | t }}</label>
        <input class="input-default form-control w-100" name="customer[bill_address_attributes][zipcode]"
               type="text"
               value="{{ customer.bill_address.zipcode }}" id="bill_zipcode">
      </div>
    </div>

    <div class="col-12 col-lg-6 mt-3">
      <div class="input-group has-validation">
        <label for="bill_city">{{ 'Postort' | t }}</label>
        <input class="input-default form-control w-100" name="customer[bill_address_attributes][city]"
               type="text"
               value="{{ customer.bill_address.city }}" id="bill_city">
      </div>
    </div>

    <div class="col-12 mt-3">
      <div class="input-group has-validation">
        <label for="bill_country">{{ 'Land' | t }} *</label>
        <select class="w-100 radius-full" name="customer[bill_address_attributes][country_id]" id="bill_country"
                required="required">
          {% for country in store.countries %}
            <option value="{{ country.id }}"
                    {% if cart.bill_address.country_id == country.id %}selected{% endif %}>{{ country.name }}</option>
          {% endfor %}
        </select>
      </div>
    </div>
  </fieldset>

  <div class="col-12 mt-3">
    <div class="form-check">
      <input class="form-check-input" type="checkbox" id="useBillRegister">
      <label class="form-check-label" for="useBillRegister">{{ 'Använd faktureringsadress som leveransadress' | t }}</label>
    </div>
  </div>

  <fieldset class="row" id="ship-section-register">
    <legend>{{ "Leveransuppgifter" | t }}</legend>
    <div class="col-12 mt-3">
      <div class="input-group has-validation">
        <label for="ship_company">{{ 'Företagsnamn' | t }} *</label>
        <input class="input-default form-control w-100" name="customer[ship_address_attributes][company]"
               type="text"
               value="{{ customer.bill_address.company }}" id="ship_company" required>
      </div>
    </div>

    <div class="col-12 mt-3">
      <div class="input-group has-validation">
        <label for="ship_address1">{{ 'Leveransadress' | t }} *</label>
        <input class="input-default form-control w-100" name="customer[ship_address_attributes][address1]"
               type="text"
               value="{{ customer.bill_address.address1 }}" id="ship_address1" required>
      </div>
    </div>

    <div class="col-12 col-lg-6 mt-3">
      <div class="input-group has-validation">
        <label for="ship_zipcode">{{ 'Postnummer' | t }} *</label>
        <input class="input-default form-control w-100" name="customer[ship_address_attributes][zipcode]"
               type="text"
               value="{{ customer.bill_address.zipcode }}" id="ship_zipcode" required>
      </div>
    </div>

    <div class="col-12 col-lg-6 mt-3">
      <div class="input-group has-validation">
        <label for="ship_city">{{ 'Postort' | t }} *</label>
        <input class="input-default form-control w-100" name="customer[ship_address_attributes][city]"
               type="text"
               value="{{ customer.bill_address.city }}" id="ship_city" required>
      </div>
    </div>

    <div class="col-12 mt-3">
      <div class="input-group has-validation">
        <label for="ship_country">{{ 'Land' | t }}</label>
        <select class="w-100 radius-full" name="customer[ship_address_attributes][country_id]" id="ship_country"
                required="required">
          {% for country in store.countries %}
            <option value="{{ country.id }}"
                    {% if customer.bill_address.country_id == country.id %}selected{% endif %}>{{ country.name }}</option>
          {% endfor %}
        </select>
      </div>
    </div>
  </fieldset>


  <fieldset class="row mt-3">
    <legend>{{ "Övriga uppgifter" | t }}</legend>
    <div class="col-12 mt-3">
      <div class="input-group has-validation">
        <label for="bill_email">{{ 'Email – för faktura' | t }}</label>
        <input class="input-default form-control w-100" name="customer[dynamic_fields][faktura-email][value]"
               type="email"
               value="{{ customer.dynamic_fields.faktura-email.value }}" id="bill_email">
      </div>
    </div>

    <div class="col-12 mt-3">
      <div class="input-group has-validation">
        <label for="gln-number">{{ 'GLN-nummer' | t }}</label>
        <input class="input-default form-control w-100" name="customer[dynamic_fields][gln-nummer][value]"
               type="text"
               value="{{ customer.dynamic_fields.gln-nummer.value }}" id="gln-number">
      </div>
    </div>

    <div class="col-12 mt-3">
      <div class="input-group has-validation">
        <label for="organisationsnummer">{{ 'Organisationsnummer' | t }}</label>
        <input class="input-default form-control w-100" name="customer[dynamic_fields][organisationsnummer][value]"
               type="text"
               value="{{ customer.dynamic_fields.organisationsnummer.value }}" id="organisationsnummer">
      </div>
    </div>
  </fieldset>


  <div class="d-flex flex-column row-gap-150">
    <div class="form-check d-flex align-items-center column-gap-75 flex-wrap">
      <input class="form-check-input" type="checkbox" name="policyAccept" id="policyAccept" required>
      <label class="form-check-label mb-0 text-md fw-regular" for="policyAccept">
        {{ "Jag godkänner" | t }} <a class="brand-link d-inline-flex" target="_blank"
                                     href="{% if locale != "sv" %}/{{ locale }}{% endif %}/policy">{{ "villkoren" | t }}</a>
      </label>
      <div class="invalid-feedback w-100">
        {{ "Du måste godkänna villkoren för att skapa ett konto" | t }}
      </div>
    </div>

    <div class="form-check d-flex align-items-center column-gap-75 flex-wrap">
      <input class="form-check-input" type="checkbox" name="customer[accept_newsletter]" id="newsletter">
      <label class="form-check-label mb-0 text-md fw-regular" for="newsletter">
        {{ "Ja, jag vill prenumerera på nyhetsbrevet" | t }}
      </label>
    </div>
  </div>

  <input type="hidden" name="customer[see_taxcoes_in_webshop]" value="false">
  <button type="submit" class="brand-button-primary">{{ "Skapa konto" | t }}</button>
</form-component>
