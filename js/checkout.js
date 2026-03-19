function initShipAddressToggle (checkboxId, sectionId) {
  const checkbox = document.getElementById(checkboxId);
  const section = document.getElementById(sectionId);
  if (!checkbox || !section) return;

  const shipInputs = Array.from(section.querySelectorAll('input, select'));
  const originalRequired = new Map(shipInputs.map(function (input) { return [input, input.required]; }));
  const MIRROR_ATTR = 'data-bill-mirrors';
  var billListeners = [];

  function createMirrors () {
    removeMirrors();
    const container = document.createElement('div');
    container.setAttribute(MIRROR_ATTR, 'true');
    shipInputs.forEach(function (input) {
      const billName = input.name.replace('[ship_address_attributes]', '[bill_address_attributes]');
      if (billName === input.name) return;
      const billInput = document.querySelector('[name="' + billName + '"]');
      if (!billInput) return;
      const hidden = document.createElement('input');
      hidden.type = 'hidden';
      hidden.name = input.name;
      hidden.value = billInput.value;
      container.appendChild(hidden);
      function syncMirror () { hidden.value = billInput.value; }
      billInput.addEventListener('input', syncMirror);
      billInput.addEventListener('change', syncMirror);
      billListeners.push({ el: billInput, fn: syncMirror });
    });
    section.parentNode.insertBefore(container, section.nextSibling);
  }

  function removeMirrors () {
    document.querySelectorAll('[' + MIRROR_ATTR + ']').forEach(function (el) { el.remove(); });
    billListeners.forEach(function (l) {
      l.el.removeEventListener('input', l.fn);
      l.el.removeEventListener('change', l.fn);
    });
    billListeners = [];
  }

  function toggle () {
    const hide = checkbox.checked;
    section.style.display = hide ? 'none' : '';
    shipInputs.forEach(function (input) {
      input.required = hide ? false : originalRequired.get(input);
      input.disabled = hide;
    });
    if (hide) {
      createMirrors();
    } else {
      removeMirrors();
    }
  }

  checkbox.addEventListener('change', toggle);
  toggle();
}

document.addEventListener('DOMContentLoaded', function () {
  initShipAddressToggle('use_bill_address', 'ship-address-fields'); // private checkout
  initShipAddressToggle('useBill', 'ship-section');                  // company checkout
  initShipAddressToggle('useBillRegister', 'ship-section-register'); // company register
});
