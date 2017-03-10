<?php



class tempclassproximity extends location_views_handler_filter_proximity{
    
    public function query() {
        //parent::query();
         if (empty($this->value)) {
            return;
          }
        
       
            // We need to merge with $this->options['value'] for filter values
            // and $this->value for exposed filter values.
            $options = array_merge($this->options, $this->options['value'], $this->value);
            $coordinates = location_views_proximity_get_reference_location($this->view, $options);

            // If we don't have any coordinates or distance, there's nothing to filter
            // by, so don't modify the query at all.
            if (empty($coordinates) || empty($this->value['search_distance'])) {
              return;
            }
            
            if(!empty(filter_xss($_REQUEST['dist'])))
            {
                $distq = filter_xss($_REQUEST['dist']);
                if($distq!=0 && ctype_digit(strval($distq))){
                   $this->value['search_distance'] = $distq;
                
                }
            }
            //dsm(40);
            $this->ensure_my_table();

            $lat = $coordinates['latitude'];
            $lon = $coordinates['longitude'];

            $distance_meters = _location_convert_distance_to_meters(
              $this->value['search_distance'],
              $this->value['search_units']
            );
            
                       
            $latrange = earth_latitude_range($lon, $lat, $distance_meters);
            $lonrange = earth_longitude_range($lon, $lat, $distance_meters);
            
            
            // Add MBR check (always).
            // In case we go past the 180/-180 mark for longitude.
            if ($lonrange[0] > $lonrange[1]) {
              $where = "$this->table_alias.latitude > :minlat AND $this->table_alias.latitude < :maxlat AND (($this->table_alias.longitude < 180 AND $this->table_alias.longitude > :minlon) OR ($this->table_alias.longitude < :maxlon AND $this->table_alias.longitude > -180))";
            }
            else {
              $where = "$this->table_alias.latitude > :minlat AND $this->table_alias.latitude < :maxlat AND $this->table_alias.longitude > :minlon AND $this->table_alias.longitude < :maxlon";
            }
            $this->query->add_where_expression(
              $this->options['group'],
              $where,
              array(
                ':minlat' => $latrange[0],
                ':maxlat' => $latrange[1],
                ':minlon' => $lonrange[0],
                ':maxlon' => $lonrange[1]
              )
            );
            
            if ($this->operator == 'dist') {
            // Add radius check.
            $this->query->add_where_expression(
              $this->options['group'],
              earth_distance_sql($lon, $lat, $this->table_alias) . ' < :distance',
              array(':distance' => $distance_meters)
            );
          }
        
    }
    
}
