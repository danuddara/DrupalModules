<?php
/**
 * @file
 * Displays the trutest_support form block.
 *
 * Available variables:
 * - $trutest_support_form: The complete search form ready for print.
 * - $trutest_support: Associative array of search elements. Can be used to print each
 *   form element separately.
 *
 * Default elements within $trutest_support:
 * - $trutest_support['trutest_support_form']: Text input area wrapped in a div.
 * - $trutest_support['actions']: Rendered form buttons.
 * - $trutest_support['hidden']: Hidden form elements. Used to validate forms when
 *   submitted.
 * @see template_preprocess_trutest_onfarmsupport_block_form()
 */
?>
<div class="trutest_onfarmsupport" id="trutest_onfarmsupport">
  <?php print $onfarmsupport_form; ?>
</div>