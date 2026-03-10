{% if cart.state == 'confirm' %}

  <div class="container">
    <div class="row justify-content-center">
      <div class="col-lg-8">
        <div class="row">

          <div class="col-12 col-sm-6 mt-3">
            <div class="input-group">
              <label>{{ 'Förnamn' | t }}</label>
              <p class="form-control-plaintext">{{ cart.bill_address.first_name }}</p>
            </div>
          </div>

          <div class="col-12 col-sm-6 mt-3">
            <div class="input-group">
              <label>{{ 'Efternamn' | t }}</label>
              <p class="form-control-plaintext">{{ cart.bill_address.last_name }}</p>
            </div>
          </div>

          <div class="col-12 mt-3">
            <div class="input-group">
              <label>{{ 'Email' | t }}</label>
              <p class="form-control-plaintext">{{ cart.email }}</p>
            </div>
          </div>

          <div class="col-12 mt-3">
            <div class="input-group">
              <label>{{ 'Faktureringsadress' | t }}</label>
              <p class="form-control-plaintext">{{ cart.bill_address.address1 }}</p>
            </div>
          </div>

          <div class="col-12 col-lg-6 mt-3">
            <div class="input-group">
              <label>{{ 'Postnummer' | t }}</label>
              <p class="form-control-plaintext">{{ cart.bill_address.zipcode }}</p>
            </div>
          </div>

          <div class="col-12 col-lg-6 mt-3">
            <div class="input-group">
              <label>{{ 'Postort' | t }}</label>
              <p class="form-control-plaintext">{{ cart.bill_address.city }}</p>
            </div>
          </div>

          <div class="col-12 mt-3">
            <div class="input-group">
              <label>{{ 'Leveransadress' | t }}</label>
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

  <form-component action="/w/cart" auto-submit="true" event="invoice:success" redirect="/w/checkout/confirm">
    <div class="container">
      <div class="row justify-content-center">
        <div class="col-lg-8">
          <div class="row">

            <div class="col-12 col-sm-6 mt-3">
              <div class="input-group has-validation">
                <label for="bill_first_name">{{ 'Förnamn' | t }}</label>
                <input class="input-default form-control w-100" name="order[bill_address_attributes][first_name]"
                       type="text"
                       value="{{ cart.bill_address.first_name  }}" id="bill_first_name" required>
              </div>
            </div>

            <div class="col-12 col-sm-6 mt-3">
              <div class="input-group has-validation">
                <label for="bill_last_name">{{ 'Efternamn' | t }}</label>
                <input class="input-default form-control w-100" name="order[bill_address_attributes][last_name]"
                       type="text"
                       value="{{ cart.bill_address.last_name  }}" id="bill_last_name" required>
              </div>
            </div>

            <div class="col-12 mt-3">
              <div class="input-group has-validation">
                <label for="order_email">{{ 'Email' | t }}</label>
                <input class="input-default form-control w-100" name="order[email]" type="email"
                       value="{{ cart.email  }}" id="order_email" required>
              </div>
            </div>

            <div class="col-12 mt-3">
              <div class="input-group has-validation">
                <label for="bill_address1">{{ 'Faktureringsadress' | t }}</label>
                <input class="input-default form-control w-100" name="order[bill_address_attributes][address1]"
                       type="text"
                       value="{{ cart.bill_address.address1  }}" id="bill_address1" required>
              </div>
            </div>

            <div class="col-12 col-lg-6 mt-3">
              <div class="input-group has-validation">
                <label for="bill_zipcode">{{ 'Postnummer' | t }}</label>
                <input class="input-default form-control w-100" name="order[bill_address_attributes][zipcode]" type="text"
                       value="{{ cart.bill_address.zipcode  }}" id="bill_zipcode" required>
              </div>
            </div>

            <div class="col-12 col-lg-6 mt-3">
              <div class="input-group has-validation">
                <label for="bill_city">{{ 'Postort' | t }}</label>
                <input class="input-default form-control w-100" name="order[bill_address_attributes][city]" type="text"
                       value="{{ cart.bill_address.city  }}" id="bill_city" required>
              </div>
            </div>

            <div class="col-12 mt-3">
              <div class="input-group has-validation">
                <label for="ship_address1">{{ 'Leveransadress' | t }}</label>
                <input class="input-default form-control w-100" name="order[ship_address_attributes][address1]"
                       type="text"
                       value="{{ cart.ship_address.address1  }}" id="ship_address1" required>
              </div>
            </div>

            <div class="col-12 col-lg-6 mt-3">
              <div class="input-group has-validation">
                <label for="ship_zipcode">{{ 'Postnummer' | t }}</label>
                <input class="input-default form-control w-100" name="order[ship_address_attributes][zipcode]" type="text"
                       value="{{ cart.ship_address.zipcode  }}" id="ship_zipcode" required>
              </div>
            </div>

            <div class="col-12 col-lg-6 mt-3">
              <div class="input-group has-validation">
                <label for="ship_city">{{ 'Postort' | t }}</label>
                <input class="input-default form-control w-100" name="order[ship_address_attributes][city]" type="text"
                       value="{{ cart.ship_address.city  }}" id="ship_city" required>
              </div>
            </div>

            <input type="hidden" name="order[bill_address_attributes][country_id]"
                   value="{{ store.countries.first.id }}">
            <input type="hidden" name="order[ship_address_attributes][country_id]"
                   value="{{ store.countries.first.id  }}">

            <div class="col-12">
              <button type="submit" class="brand-button-primary mt-3">{{ "Betala" | t }}</button>
            </div>

            <input type="hidden" name="_method" value="patch">

          </div>
        </div>
      </div>
    </div>
  </form-component>

{% endif %}


<script>
  window.addEventListener('invoice:success', (e) => {
    console.log(e);
  });
</script>
