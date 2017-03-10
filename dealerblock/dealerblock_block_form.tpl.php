<?php
/**
 * @file
 * Displays the trutest_dealers form block.
 *
 * Available variables:
 * - $trutest_dealers_form: The complete search form ready for print.
 * - $trutest_dealers: Associative array of search elements. Can be used to print each
 *   form element separately.
 *
 * Default elements within $trutest_dealers:
 * - $trutest_dealers['trutest_dealers_form']: Text input area wrapped in a div.
 * - $trutest_dealers['actions']: Rendered form buttons.
 * - $trutest_dealers['hidden']: Hidden form elements. Used to validate forms when
 *   submitted.
 * @see template_preprocess_trutest_dealers_block_form()
 */
?>
<div class="trutest_dealerblock" id="trutest_dealerblock">
  <?php print $dealerblock_form; ?>
</div>