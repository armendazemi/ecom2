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