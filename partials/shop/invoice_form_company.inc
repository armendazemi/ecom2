{{cart.state}}
{% if cart.state == 'confirm' %}
  <div class="container">
    <div class="row justify-content-center">
      <div class="col-lg-8">
        <div class="row">

          <fieldset class="row mt-3">
            <legend>{{ "Leveransuppgifter" | t }}</legend>
            <div class="col-12 mt-3">
              <div class="input-group">
                <label>{{ 'Företagsnamn' | t }} *</label>
                <p class="form-control-plaintext">{{ cart.bill_address.company }}</p>
              </div>
            </div>

            <div class="col-12 mt-3">
              <div class="input-group">
                <label>{{ 'Mottagning' | t }} *</label>
                <p class="form-control-plaintext">{{ cart.dynamic_fields.mottagning.value }}</p>
              </div>
            </div>

            <div class="col-12 mt-3">
              <div class="input-group">
                <label>{{ 'Leveransadress' | t }} *</label>
                <p class="form-control-plaintext">{{ cart.bill_address.address1 }}</p>
              </div>
            </div>

            <div class="col-12 col-lg-6 mt-3">
              <div class="input-group">
                <label>{{ 'Postnummer' | t }} *</label>
                <p class="form-control-plaintext">{{ cart.bill_address.zipcode }}</p>
              </div>
            </div>

            <div class="col-12 col-lg-6 mt-3">
              <div class="input-group">
                <label>{{ 'Postort' | t }} *</label>
                <p class="form-control-plaintext">{{ cart.bill_address.city }}</p>
              </div>
            </div>

            <div class="col-12 mt-3">
              <div class="input-group">
                <label>{{ 'Land' | t }} *</label>
                <p class="form-control-plaintext">{{ cart.bill_address.country.name }}</p>
              </div>
            </div>
          </fieldset>

          <fieldset class="row mt-3">
            <legend>{{ "Faktureringsuppgifter " | t }}</legend>
            <div class="col-12 mt-3">
              <div class="input-group">
                <label>{{ 'Företagsnamn' | t }}</label>
                <p class="form-control-plaintext">{{ cart.dynamic_fields.fakt-company.value }}</p>
              </div>
            </div>

            <div class="col-12 mt-3">
              <div class="input-group">
                <label>{{ 'Faktureringsadress' | t }}</label>
                <p class="form-control-plaintext">{{ cart.ship_address.address1 }}</p>
              </div>
            </div>

            <div class="col-12 col-lg-6 mt-3">
              <div class="input-group">
                <label>{{ 'Postnummer' | t }}</label>
                <p class="form-control-plaintext">{{ cart.ship_address.zipcode }}</p>
              </div>
            </div>

            <div class="col-12 col-lg-6 mt-3">
              <div class="input-group">
                <label>{{ 'Postort' | t }}</label>
                <p class="form-control-plaintext">{{ cart.ship_address.city }}</p>
              </div>
            </div>

            <div class="col-12 mt-3">
              <div class="input-group">
                <label>{{ 'Land' | t }}</label>
                <p class="form-control-plaintext">{{ cart.ship_address.country.name }}</p>
              </div>
            </div>
          </fieldset>

          <fieldset class="row mt-3">
            <legend>{{ "Övriga uppgifter" | t }}</legend>
            <div class="col-lg-6 mt-3">
              <div class="input-group">
                <label>{{ 'Referensnummer/Beställarid' | t }} *</label>
                <p class="form-control-plaintext">{{ cart.dynamic_fields.referensnummer.value }}</p>
              </div>
            </div>

            <div class="col-lg-6 mt-3">
              <div class="input-group">
                <label>{{ "Beställarens namn" | t }} *</label>
                <p class="form-control-plaintext">{{ cart.dynamic_fields.order-namn.value }}</p>
              </div>
            </div>

            <div class="col-12 mt-3">
              <div class="input-group">
                <label>{{ 'Email – för paketavisering' | t }} *</label>
                <p class="form-control-plaintext">{{ cart.email }}</p>
              </div>
            </div>

            <div class="col-12 mt-3">
              <div class="input-group">
                <label>{{ 'Email – för faktura' | t }}</label>
                <p class="form-control-plaintext">{{ cart.dynamic_fields.faktura-email.value }}</p>
              </div>
            </div>

            <div class="col-12 mt-3">
              <div class="input-group">
                <label>{{ 'GLN-nummer' | t }}</label>
                <p class="form-control-plaintext">{{ cart.dynamic_fields.gln-nummer.value }}</p>
              </div>
            </div>

            <div class="col-12 mt-3">
              <div class="input-group">
                <label>{{ 'Organisationsnummer' | t }}</label>
                <p class="form-control-plaintext">{{ cart.dynamic_fields.organisationsnummer.value }}</p>
              </div>
            </div>

            <div class="col-12 mt-3">
              <div class="input-group">
                <label>{{ 'Meddelande' | t }}</label>
                <p class="form-control-plaintext">{{ cart.special_instructions }}</p>
              </div>
            </div>
          </fieldset>

          <div class="col-12 mt-3">
            <div class="d-flex flex-wrap gap-150">
              <a href="/w/checkout/address" class="brand-button-secondary">{{ 'Tillbaka' | t }}</a>
              <a href="/w/checkout/complete" class="brand-button-primary">{{ "Slutför" | t }}</a>
            </div>
          </div>

        </div>
      </div>
    </div>
  </div>




{% else %}
  <form-component no-clear action="/w/cart" redirect="/w/checkout/confirm" redirect="/w/checkout/confirm">
    <div class="container">
      <div class="row justify-content-center">
        <div class="col-lg-8">
          <div class="row">

            <fieldset class="row mt-3">
              <legend>{{ "Faktureringsuppgifter " | t }}</legend>
              <div class="col-12 mt-3">
                <div class="input-group has-validation">
                  <label for="bill_company">{{ 'Företagsnamn' | t }}</label>
                  <input class="input-default form-control w-100" name="order[bill_address_attributes][company]"
                         type="text"
                         value="{{ cart.bill_address.company }}" id="bill_company">
                </div>
              </div>

              <div class="col-12 mt-3">
                <div class="input-group has-validation">
                  <label for="bill_address1">{{ 'Faktureringsadress' | t }}</label>
                  <input class="input-default form-control w-100" name="order[bill_address_attributes][address1]"
                         type="text"
                         value="{{ cart.bill_address.address1 }}" id="bill_address1">
                </div>
              </div>

              <div class="col-12 col-lg-6 mt-3">
                <div class="input-group has-validation">
                  <label for="bill_zipcode">{{ 'Postnummer' | t }}</label>
                  <input class="input-default form-control w-100" name="order[bill_address_attributes][zipcode]"
                         type="text"
                         value="{{ cart.bill_address.zipcode }}" id="bill_zipcode">
                </div>
              </div>

              <div class="col-12 col-lg-6 mt-3">
                <div class="input-group has-validation">
                  <label for="bill_city">{{ 'Postort' | t }}</label>
                  <input class="input-default form-control w-100" name="order[bill_address_attributes][city]"
                         type="text"
                         value="{{ cart.bill_address.city }}" id="bill_city">
                </div>
              </div>

              <div class="col-12 mt-3">
                <div class="input-group has-validation">
                  <label for="bill_country">{{ 'Land' | t }}</label>
                  <select class="w-100 radius-full" name="order[bill_address_attributes][country_id]" id="bill_country"
                          required="required">
                    {% for country in store.countries %}
                      <option value="{{ country.id }}"
                              {% if cart.bill_address.country_id == country.id %}selected{% endif %}>{{ country.name }}</option>
                    {% endfor %}
                  </select>
                </div>
              </div>

              <div class="col-12 mt-3">
                <div class="form-check">
                  <input class="form-check-input" type="checkbox" id="useBill">
                  <label class="form-check-label"
                         for="useBill">{{ 'Använd fakturaadress som leveransadress' | t }}</label>
                </div>
              </div>
            </fieldset>


            <fieldset class="row mt-3" id="ship-section">
              <legend>{{ "Leveransuppgifter" | t }}</legend>
              <div class="col-12 mt-3">
                <div class="input-group has-validation">
                  <label for="ship_company">{{ 'Företagsnamn' | t }} *</label>
                  <input class="input-default form-control w-100" name="order[ship_address_attributes][company]"
                         type="text"
                         value="{{ cart.bill_address.company }}" id="ship_company" required>
                </div>
              </div>

              <div class="col-12 mt-3">
                <div class="input-group has-validation">
                  <label for="mottagning">{{ 'Mottagning' | t }} *</label>
                  <input class="input-default form-control w-100" name="order[dynamic_fields][mottagning][value]"
                         type="text"
                         value="{{ cart.dynamic_fields.mottagning.value }}" id="mottagning" required>
                </div>
              </div>

              <div class="col-12 mt-3">
                <div class="input-group has-validation">
                  <label for="ship_address1">{{ 'Leveransadress' | t }} *</label>
                  <input class="input-default form-control w-100" name="order[ship_address_attributes][address1]"
                         type="text"
                         value="{{ cart.bill_address.address1 }}" id="ship_address1" required>
                </div>
              </div>

              <div class="col-12 col-lg-6 mt-3">
                <div class="input-group has-validation">
                  <label for="ship_zipcode">{{ 'Postnummer' | t }} *</label>
                  <input class="input-default form-control w-100" name="order[ship_address_attributes][zipcode]"
                         type="text"
                         value="{{ cart.bill_address.zipcode }}" id="ship_zipcode" required>
                </div>
              </div>

              <div class="col-12 col-lg-6 mt-3">
                <div class="input-group has-validation">
                  <label for="ship_city">{{ 'Postort' | t }} *</label>
                  <input class="input-default form-control w-100" name="order[ship_address_attributes][city]"
                         type="text"
                         value="{{ cart.bill_address.city }}" id="ship_city" required>
                </div>
              </div>

              <div class="col-12 mt-3">
                <div class="input-group has-validation">
                  <label for="ship_country">{{ 'Land' | t }} *</label>
                  <select class="w-100 radius-full" name="order[ship_address_attributes][country_id]" id="ship_country"
                          required="required">
                    {% for country in store.countries %}
                      <option value="{{ country.id }}"
                              {% if cart.bill_address.country_id == country.id %}selected{% endif %}>{{ country.name }}</option>
                    {% endfor %}
                  </select>
                </div>
              </div>
            </fieldset>

            <fieldset class="row mt-3">
              <legend>{{ "Övriga uppgifter" | t }}</legend>
              <div class="col-lg-6 mt-3">
                <div class="input-group has-validation">
                  <label for="referensnummer">{{ 'Referensnummer/Beställarid' | t }} *</label>
                  <input class="input-default form-control w-100" name="order[dynamic_fields][referensnummer][value]"
                         type="text"
                         value="{{ cart.dynamic_fields.referensnummer.value }}" id="referensnummer" required>
                </div>
              </div>

              <div class="col-lg-6 mt-3">
                <div class="input-group has-validation">
                  <label for="order-namn">{{ "Beställarens namn" | t }} *</label>
                  <input class="input-default form-control w-100" name="order[dynamic_fields][order-namn][value]"
                         type="text"
                         value="{{ customer.dynamic_fields.order-namn.value | fallback: cart.dynamic_fields.order-namn.value }}"
                         id="order-namn" required>
                </div>
              </div>

              <div class="col-12 mt-3">
                <div class="input-group has-validation">
                  <label for="order_email">{{ 'Email – för paketavisering' | t }} *</label>
                  <input class="input-default form-control w-100" name="order[email]" type="email"
                         value="{{ cart.email }}" id="order_email" required>
                </div>
              </div>

              <div class="col-12 mt-3">
                <div class="input-group has-validation">
                  <label for="bill_email">{{ 'Email – för faktura' | t }}</label>
                  <input class="input-default form-control w-100" name="order[dynamic_fields][faktura-email][value]"
                         type="email"
                         value="{{ customer.dynamic_fields.faktura-email.value | fallback: cart.dynamic_fields.faktura-email.value }}"
                         id="bill_email">
                </div>
              </div>

              <div class="col-12 mt-3">
                <div class="input-group has-validation">
                  <label for="gln-number">{{ 'GLN-nummer' | t }}</label>
                  <input class="input-default form-control w-100" name="order[dynamic_fields][gln-nummer][value]"
                         type="text"
                         value="{{ customer.dynamic_fields.gln-nummer.value | fallback: cart.dynamic_fields.gln-nummer.value }}"
                         id="gln-number">
                </div>
              </div>

              <div class="col-12 mt-3">
                <div class="input-group has-validation">
                  <label for="organisationsnummer">{{ 'Organisationsnummer' | t }}</label>
                  <input class="input-default form-control w-100"
                         name="order[dynamic_fields][organisationsnummer][value]"
                         type="text"
                         value="{{ customer.dynamic_fields.organisationsnummer.value | fallback: cart.dynamic_fields.organisationsnummer.value }}"
                         id="organisationsnummer">
                </div>
              </div>

              <div class="col-12 mt-3">
                <div class="input-group has-validation">
                  <label for="meddelande">{{ 'Meddelande' | t }}</label>
                  <textarea class="input-default form-control h-auto padding-150 w-100" rows="5"
                            name="order[special_instructions]"
                            id="meddelande">{{ cart.special_instructions.value }}</textarea>
                </div>
              </div>
            </fieldset>

            <div class="col-12">
              <button type="submit" class="brand-button-primary mt-3">{{ "Beställ" | t }}</button>
            </div>

            <input type="hidden" name="_method" value="patch">

          </div>
        </div>
      </div>
    </div>
  </form-component>

{% endif %}

