<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function dealerblock_views_data_alter(&$data) {
      //dsm($data);
      //$data['location']['distance']['argument']['handler'] ='tempclass_argument_location_proximity';
      $data['location']['distance']['filter']['handler'] = 'tempclassproximity';
     
}
